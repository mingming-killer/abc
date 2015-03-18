# abc
a android awesome log recorder from ingenic.


# how to use
* 1. you can put the abc module to external/ in framework code path.

* 2. add the abc module to the build mk file:
  e.g: device/vendor/product/device.mk:  

<pre>
# when in eng we add the abc log recorder.
ifeq ($(TARGET_BUILD_VARIANT),eng)
PRODUCT_PACKAGES += abc 
endif

# the custom overlay init.rc
PRODUCT_COPY_FILES += \
    device/$(VENDOR)/$(TARGET_PRODUCT)/init.$(TARGET_BOARD_HARDWARE).rc:root/init.$(TARGET_BOARD_HARDWARE).rc \
</pre>

* 3. add the abc daemon process in init.rc:
  e.g: device/vendor/product/init.board.rc:

<pre>
# abc daemon process
service abc /system/bin/abc
    class main
    disable

# in eng we start abc service
on property:ro.build.type=eng
    start abc 
</pre>


# origin description

abc(android bug collector) is an automatic bug report tool.It has four functions:

1. record kernel log
2. record logcat log
3. record process 
4. send mail

Before use it should config it,very simple

	cd src/
	open config.h

Config option:
	
	MAIL_SERVER:		send server(default mail.ingenic.cn)
	MAIL_SENDRE:		sender mail
	MAIL_RECIPIENT:		recipient mail
	FROM:		-----
	TO:		     |--mail subject
	SUBJECT:	-----
	USER_NAME:		mail sender name(must same as MAIL_SENDER)
	USER_PASSWORD:		mail sender password

	SYSTEM_PATH:		system log record path
				(default /data/syslog)

	ITERM_MAX:		max numbers of directory entry in system
				log directory(default 100)

	SYS_LOG_MAX:		max numbers of system log(default 10) 

	LOGCAT_PRIOR:		android log message priority
				“V”	— Verbose(lowest priority) 
				“D”	— Debug 
				“I”	— Info 
				“W”	— Warning(default)
 				“E”	— Error 
				“F“	— Fatal 
				”S“	— Silent
				(highest priority, on which nothing is ever
				printed)
	
	CONFIG_KERNEL_LOG:	enable kernel log catch
	CONFIG_LOGCAT_LOG:	enable logcat log catch
	CONFIG_PROCESS_LOG:	enable process log catch
	CONFIG_SEND_MAIL:	enable mail send(default disable)

You need change them adapt to your apply.Current version does not support
SSL encryption for transmission,recommend to use of the ingenic mail 
server(mail.ingenic.cn),future version will support it and do more.

abc is copright(C) 2012 by Jamin Cheung<ymzhang@ingenic.cn>, and is licensed
under the terms of GNU General Public License version 2.
See the file LICENSE for more information.

