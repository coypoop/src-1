/*	$NetBSD: timer.h,v 1.7 2019/10/13 22:32:09 christos Exp $	*/

/*-
 * Copyright (c) 2013 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Taylor R. Campbell.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Notes on porting:
 *
 * - Linux does not have teardown_timer.  You must add it yourself in
 *   the appropriate place.
 */

#ifndef _LINUX_TIMER_H_
#define _LINUX_TIMER_H_

#include <sys/callout.h>

#include <linux/jiffies.h>
#include <linux/ktime.h>

struct timer_list {
	struct callout tl_callout;
};

#define	from_timer(V, T, F)	container_of(T, __typeof__(*(V)), F)

static inline void
timer_setup(struct timer_list *timer, void (*fn)(struct timer_list *),
    uintptr_t flags)
{

	callout_init(&timer->tl_callout, 0);

	/* XXX Super-sketchy casts!  */
	callout_setfunc(&timer->tl_callout, (void (*)(void *))(void *)fn,
	    (void *)flags);
}

static inline void
teardown_timer(struct timer_list *timer)
{

	callout_destroy(&timer->tl_callout);
}

static inline void
mod_timer(struct timer_list *timer, unsigned long then)
{
	const unsigned long now = jiffies;

	callout_schedule(&timer->tl_callout, (now < then? (then - now) : 0));
}

static inline void
mod_timer_pinned(struct timer_list *timer, unsigned long then)
{

	/* XXX Stay on the same CPU it was originally on...  */
	mod_timer(timer, then);
}

static inline void
del_timer(struct timer_list *timer)
{

	callout_stop(&timer->tl_callout);
}

static inline bool
del_timer_sync(struct timer_list *timer)
{

	/* XXX return values? */
	return callout_halt(&timer->tl_callout, NULL);
}

static inline bool
timer_pending(struct timer_list *timer)
{

	return callout_pending(&timer->tl_callout);
}

/*
 * XXX This is bogus -- the Linux version does various machinations to
 * give some jitter so that stuff doesn't wake up all at once.
 */

static inline unsigned long
round_jiffies_up(unsigned long j)
{
	return roundup(j, hz);
}

static inline unsigned long
round_jiffies_up_relative(unsigned long j)
{
	return roundup(j, hz);
}

#endif  /* _LINUX_TIMER_H_ */
