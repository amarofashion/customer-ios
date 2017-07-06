//
//  KUSAPIClient.h
//  Kustomer
//
//  Created by Daniel Amitay on 7/4/17.
//  Copyright © 2017 Kustomer. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KUSChatSession.h"
#import "KUSChatSettings.h"
#import "KUSChatMessage.h"
#import "KUSCustomer.h"
#import "KUSTrackingToken.h"
#import "KUSPaginatedResponse.h"

@interface KUSAPIClient : NSObject

- (instancetype)initWithOrgName:(NSString *)orgName;

- (void)getCurrentTrackingToken:(void(^)(NSError *error, KUSTrackingToken *trackingToken))completion;
- (void)getChatSettings:(void(^)(NSError *error, KUSChatSettings *chatSettings))completion;
- (void)getChatSessions:(void(^)(NSError *error, KUSPaginatedResponse *chatSessions))completion;
- (void)getMessagesForSessionId:(NSString *)sessionId completion:(void(^)(NSError *error, KUSPaginatedResponse *chatMessages))completion;
- (void)getChatSessionFoId:(NSString *)sessionId completion:(void(^)(NSError *error, KUSChatSession *session))completion;

- (void)createChatSessionWithTitle:(NSString *)title completion:(void(^)(NSError *error, KUSChatSession *session))completion;
- (void)updateLastSeenAtForSessionId:(NSString *)sessionId completion:(void(^)(NSError *error, KUSChatSession *session))completion;
- (void)sendMessage:(NSString *)message toChatSession:(NSString *)sessionId completion:(void(^)(NSError *error, KUSChatMessage *message))completion;

- (void)describe:(NSDictionary *)description completion:(void(^)(NSError *error, KUSCustomer *customer))completion;
- (void)identify:(NSDictionary *)identity completion:(void(^)(NSError *error))completion;
- (void)clearTrackingToken:(void(^)(NSError *error, KUSTrackingToken *trackingToken))completion;

- (instancetype)init NS_UNAVAILABLE;

@end
