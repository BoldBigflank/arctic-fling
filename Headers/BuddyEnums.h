
/*
 * Copyright (C) 2012 Buddy Platform, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */


#import <Foundation/Foundation.h>


/**
 * PUSH Notification servers Enum
 */
typedef enum
{
	PushServer_SandBoxPNS = 0,
	PushServer_ProductionPNS = 1
} PushServer;

/**
 * UserGender Enum
 */
typedef enum
{
	UserGender_Male = 1,
	UserGender_Female = 2,
	UserGender_Any = 3
} UserGender;

/**
 * UserStatus Enum
 */
typedef enum
{
	UserStatus_Single = 1,
	UserStatus_Dating = 2,
	UserStatus_Engaged = 3,
	UserStatus_Married = 4,
	UserStatus_Divorced = 5,
	UserStatus_Widowed = 6,
	UserStatus_OnTheProwl = 7,
	UserStatus_AnyUserStatus = -1
} UserStatus;