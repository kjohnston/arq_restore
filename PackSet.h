/*
 Copyright (c) 2009, Stefan Reitshamer http://www.haystacksoftware.com
 
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 
 * Neither the names of PhotoMinds LLC or Haystack Software, nor the names of 
 their contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */ 

#import <Cocoa/Cocoa.h>
@class Blob;
@class S3Service;
@class ServerBlob;

@interface PackSet : NSObject {
    NSString *packSetName;
    NSString *escapedPackSetName;
    NSString *packSetDir;
    S3Service *s3;
    NSString *s3BucketName;
    NSString *computerUUID;
    BOOL keepPacksLocal;
    NSMutableSet *packSHA1s;
    NSString *currentPackSHA1;
    NSMutableDictionary *packIndexEntries;
}
+ (NSString *)errorDomain;
+ (unsigned long long)maxPackFileSizeMB;
+ (unsigned long long)maxPackItemSizeBytes;
+ (NSString *)s3PathWithS3BucketName:(NSString *)theS3BucketName computerUUID:(NSString *)theComputerUUID packSetName:(NSString *)thePackSetName;
+ (NSString *)localPathWithComputerUUID:(NSString *)theComputerUUID packSetName:(NSString *)thePackSetName;

- (id)initWithName:(NSString *)thePackSetName 
         s3Service:(S3Service *)theS3 
      s3BucketName:(NSString *)theS3BucketName 
      computerUUID:(NSString *)theComputerUUID 
    keepPacksLocal:(BOOL)isKeepPacksLocal 
         packSHA1s:(NSArray *)thePackSHA1s 
             error:(NSError **)error;
- (NSString *)name;
- (ServerBlob *)newServerBlobForSHA1:(NSString *)sha1 error:(NSError **)error;
- (BOOL)containsBlobForSHA1:(NSString *)sha1;
- (NSString *)packSHA1ForPackedBlobSHA1:(NSString *)blobSHA1;
@end
