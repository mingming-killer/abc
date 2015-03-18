/*
 * Copyright(C) 2012 Ingenic Semiconductor Inc.
 * Authors: Jamin Cheung <ymzhang@ingenic.cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#define SYSTEM_PATH	"/data/syslog"

/* Mime subject */
#define FROM	"from@ingenic.cn"
#define TO	"to@example.com"
#define SUBJECT	"Subject Example"

/* Mail sender and recipient */
#define MAIL_SERVER	"mail.ingenic.cn"
#define MAIL_SENDER	"from@ingenic.cn"
#define MAIL_RECIPIENT	"to@example.com"

/* User name and password */
#define	USER_NAME	"username@ingenic.cn\n"
#define	USER_PASSWORD	"userpasseord"

/*Logcat priority is one of the following character values,
 *ordered from lowest to highest priority:
 *V — Verbose (lowest priority)
 *D — Debug
 *I — Info
 *W — Warning
 *E — Error
 *F — Fatal
 *S — Silent (highest priority, on which nothing is ever printed)
 */
#define LOGCAT_PRIOR	"V"

/* Function config */
#define	CONFIG_KERNEL_LOG
#define CONFIG_LOGCAT_LOG
//#define CONFIG_PROCESS_LOG
//#define CONFIG_SEND_MAIL

/* config all files numbers in SYSTEM_PATH
 * usually keep default configure---100
 */
#define ITERM_MAX	100

/* config syslog max numbers */
#define SYS_LOG_MAX	3

#include <cutils/log.h>

#endif
