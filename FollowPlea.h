//
//  FollowPlea.h
//  FollowPlea
//
//  Created by TapSharp on 28/19/2015.
//
//  The MIT License (MIT)
//
//  Copyright (c) 2015 TapSharp
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <Social/Social.h>
#import <Accounts/Accounts.h>
#import <SpringBoard/SBLockScreenManager.h>
#import "UIAlertView+Blocks/UIAlertView+Blocks.h"

/**
 * Customise Lingo
 *
 * Useful if your tweak is multilingual!
 */

#ifndef FP_PLEA_MSG_TITLE
#define FP_PLEA_MSG_TITLE @"Thanks for Installing!"
#endif

#ifndef FP_PLEA_MSG_BODY
#define FP_PLEA_MSG_BODY @"A lot of hard work goes into making tweaks. Please consider following me on Twitter!"
#endif

#ifndef FP_CANCEL_LABEL
#define FP_CANCEL_LABEL @"No Thanks"
#endif

#ifndef FP_OKAY_LABEL
#define FP_OKAY_LABEL @"Okay Sure"
#endif

#ifndef FP_WHICH_ACCOUNT_TITLE
#define FP_WHICH_ACCOUNT_TITLE @"Which Account?"
#endif

#ifndef FP_WHICH_ACCOUNT_BODY
#define FP_WHICH_ACCOUNT_BODY @"Select an account to follow with."
#endif

#ifndef FP_ALL_ACCOUNTS_LABEL
#define FP_ALL_ACCOUNTS_LABEL @"All Accounts!"
#endif

#ifndef FP_TWITTER_SCREENNAME
#define FP_TWITTER_SCREENNAME @"TapSharp"
#endif

#ifndef FP_CALLBACK_HANDLER
#define FP_CALLBACK_HANDLER(data, urlResponse, error){}
#endif


static void fpFollowTwitterAccount(ACAccount *twitterAccount) {
	NSMutableDictionary *tempDict = [NSMutableDictionary dictionary];
	[tempDict setValue:FP_TWITTER_SCREENNAME forKey:@"screen_name"];
	[tempDict setValue:@"true" forKey:@"follow"];
	SLRequest *postRequest = [SLRequest requestForServiceType:SLServiceTypeTwitter requestMethod:SLRequestMethodPOST URL:[NSURL URLWithString:@"https://api.twitter.com/1/friendships/create.json"] parameters:tempDict];
	[postRequest setAccount:twitterAccount];
	[postRequest performRequestWithHandler:^(NSData *responseData, NSHTTPURLResponse *urlResponse, NSError *error) {
		FP_CALLBACK_HANDLER(responseData, urlResponse, error);
	}];
}