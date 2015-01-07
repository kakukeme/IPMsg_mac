/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: main.m
 *	Module		:
 *	Description	: Xcode Auto Create
 *============================================================================*/

#import <Cocoa/Cocoa.h>

int main(int argc, const char *argv[])
{
    //调用signal(SIGPIPE, SIG_IGN), SIGPIPE 信号时就不会中止程序，直接把这个信号忽略掉。
	signal(SIGPIPE, SIG_IGN);
	return NSApplicationMain(argc, argv);
}
