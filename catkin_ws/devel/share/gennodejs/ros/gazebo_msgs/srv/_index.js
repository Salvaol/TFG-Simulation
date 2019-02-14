
"use strict";

let GetModelProperties = require('./GetModelProperties.js')
let DeleteModel = require('./DeleteModel.js')
let SetModelState = require('./SetModelState.js')
let GetJointProperties = require('./GetJointProperties.js')
let ApplyJointEffort = require('./ApplyJointEffort.js')
let GetLightProperties = require('./GetLightProperties.js')
let SetLightProperties = require('./SetLightProperties.js')
let ApplyBodyWrench = require('./ApplyBodyWrench.js')
let GetModelState = require('./GetModelState.js')
let SetJointTrajectory = require('./SetJointTrajectory.js')
let SetLinkState = require('./SetLinkState.js')
let SetJointProperties = require('./SetJointProperties.js')
let GetLinkProperties = require('./GetLinkProperties.js')
let SetLinkProperties = require('./SetLinkProperties.js')
let SetPhysicsProperties = require('./SetPhysicsProperties.js')
let GetLinkState = require('./GetLinkState.js')
let GetWorldProperties = require('./GetWorldProperties.js')
let BodyRequest = require('./BodyRequest.js')
let GetPhysicsProperties = require('./GetPhysicsProperties.js')
let JointRequest = require('./JointRequest.js')
let SetModelConfiguration = require('./SetModelConfiguration.js')
let SpawnModel = require('./SpawnModel.js')
let DeleteLight = require('./DeleteLight.js')

module.exports = {
  GetModelProperties: GetModelProperties,
  DeleteModel: DeleteModel,
  SetModelState: SetModelState,
  GetJointProperties: GetJointProperties,
  ApplyJointEffort: ApplyJointEffort,
  GetLightProperties: GetLightProperties,
  SetLightProperties: SetLightProperties,
  ApplyBodyWrench: ApplyBodyWrench,
  GetModelState: GetModelState,
  SetJointTrajectory: SetJointTrajectory,
  SetLinkState: SetLinkState,
  SetJointProperties: SetJointProperties,
  GetLinkProperties: GetLinkProperties,
  SetLinkProperties: SetLinkProperties,
  SetPhysicsProperties: SetPhysicsProperties,
  GetLinkState: GetLinkState,
  GetWorldProperties: GetWorldProperties,
  BodyRequest: BodyRequest,
  GetPhysicsProperties: GetPhysicsProperties,
  JointRequest: JointRequest,
  SetModelConfiguration: SetModelConfiguration,
  SpawnModel: SpawnModel,
  DeleteLight: DeleteLight,
};
