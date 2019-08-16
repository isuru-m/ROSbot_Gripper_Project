; Auto-generated. Do not edit!


(cl:in-package gripper_pkg-srv)


;//! \htmlinclude servoService-request.msg.html

(cl:defclass <servoService-request> (roslisp-msg-protocol:ros-message)
  ((radius
    :reader radius
    :initarg :radius
    :type cl:float
    :initform 0.0))
)

(cl:defclass servoService-request (<servoService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servoService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servoService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gripper_pkg-srv:<servoService-request> is deprecated: use gripper_pkg-srv:servoService-request instead.")))

(cl:ensure-generic-function 'radius-val :lambda-list '(m))
(cl:defmethod radius-val ((m <servoService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gripper_pkg-srv:radius-val is deprecated.  Use gripper_pkg-srv:radius instead.")
  (radius m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servoService-request>) ostream)
  "Serializes a message object of type '<servoService-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'radius))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servoService-request>) istream)
  "Deserializes a message object of type '<servoService-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radius) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servoService-request>)))
  "Returns string type for a service object of type '<servoService-request>"
  "gripper_pkg/servoServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servoService-request)))
  "Returns string type for a service object of type 'servoService-request"
  "gripper_pkg/servoServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servoService-request>)))
  "Returns md5sum for a message object of type '<servoService-request>"
  "397e5d9373b2d6be3b1e90928218304b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servoService-request)))
  "Returns md5sum for a message object of type 'servoService-request"
  "397e5d9373b2d6be3b1e90928218304b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servoService-request>)))
  "Returns full string definition for message of type '<servoService-request>"
  (cl:format cl:nil "float32 radius~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servoService-request)))
  "Returns full string definition for message of type 'servoService-request"
  (cl:format cl:nil "float32 radius~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servoService-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servoService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'servoService-request
    (cl:cons ':radius (radius msg))
))
;//! \htmlinclude servoService-response.msg.html

(cl:defclass <servoService-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass servoService-response (<servoService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servoService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servoService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gripper_pkg-srv:<servoService-response> is deprecated: use gripper_pkg-srv:servoService-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <servoService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gripper_pkg-srv:success-val is deprecated.  Use gripper_pkg-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servoService-response>) ostream)
  "Serializes a message object of type '<servoService-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servoService-response>) istream)
  "Deserializes a message object of type '<servoService-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servoService-response>)))
  "Returns string type for a service object of type '<servoService-response>"
  "gripper_pkg/servoServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servoService-response)))
  "Returns string type for a service object of type 'servoService-response"
  "gripper_pkg/servoServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servoService-response>)))
  "Returns md5sum for a message object of type '<servoService-response>"
  "397e5d9373b2d6be3b1e90928218304b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servoService-response)))
  "Returns md5sum for a message object of type 'servoService-response"
  "397e5d9373b2d6be3b1e90928218304b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servoService-response>)))
  "Returns full string definition for message of type '<servoService-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servoService-response)))
  "Returns full string definition for message of type 'servoService-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servoService-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servoService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'servoService-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'servoService)))
  'servoService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'servoService)))
  'servoService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servoService)))
  "Returns string type for a service object of type '<servoService>"
  "gripper_pkg/servoService")