; Auto-generated. Do not edit!


(cl:in-package gripper_pkg-srv)


;//! \htmlinclude stepService-request.msg.html

(cl:defclass <stepService-request> (roslisp-msg-protocol:ros-message)
  ((distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0)
   (initialise
    :reader initialise
    :initarg :initialise
    :type cl:boolean
    :initform cl:nil)
   (direction
    :reader direction
    :initarg :direction
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass stepService-request (<stepService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <stepService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'stepService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gripper_pkg-srv:<stepService-request> is deprecated: use gripper_pkg-srv:stepService-request instead.")))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <stepService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gripper_pkg-srv:distance-val is deprecated.  Use gripper_pkg-srv:distance instead.")
  (distance m))

(cl:ensure-generic-function 'initialise-val :lambda-list '(m))
(cl:defmethod initialise-val ((m <stepService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gripper_pkg-srv:initialise-val is deprecated.  Use gripper_pkg-srv:initialise instead.")
  (initialise m))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <stepService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gripper_pkg-srv:direction-val is deprecated.  Use gripper_pkg-srv:direction instead.")
  (direction m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <stepService-request>) ostream)
  "Serializes a message object of type '<stepService-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'initialise) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'direction) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <stepService-request>) istream)
  "Deserializes a message object of type '<stepService-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'initialise) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'direction) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<stepService-request>)))
  "Returns string type for a service object of type '<stepService-request>"
  "gripper_pkg/stepServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'stepService-request)))
  "Returns string type for a service object of type 'stepService-request"
  "gripper_pkg/stepServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<stepService-request>)))
  "Returns md5sum for a message object of type '<stepService-request>"
  "eddfa10760234970c83c5339187b1c40")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'stepService-request)))
  "Returns md5sum for a message object of type 'stepService-request"
  "eddfa10760234970c83c5339187b1c40")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<stepService-request>)))
  "Returns full string definition for message of type '<stepService-request>"
  (cl:format cl:nil "float32 distance~%bool initialise~%bool direction~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'stepService-request)))
  "Returns full string definition for message of type 'stepService-request"
  (cl:format cl:nil "float32 distance~%bool initialise~%bool direction~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <stepService-request>))
  (cl:+ 0
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <stepService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'stepService-request
    (cl:cons ':distance (distance msg))
    (cl:cons ':initialise (initialise msg))
    (cl:cons ':direction (direction msg))
))
;//! \htmlinclude stepService-response.msg.html

(cl:defclass <stepService-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass stepService-response (<stepService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <stepService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'stepService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gripper_pkg-srv:<stepService-response> is deprecated: use gripper_pkg-srv:stepService-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <stepService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gripper_pkg-srv:success-val is deprecated.  Use gripper_pkg-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <stepService-response>) ostream)
  "Serializes a message object of type '<stepService-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <stepService-response>) istream)
  "Deserializes a message object of type '<stepService-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<stepService-response>)))
  "Returns string type for a service object of type '<stepService-response>"
  "gripper_pkg/stepServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'stepService-response)))
  "Returns string type for a service object of type 'stepService-response"
  "gripper_pkg/stepServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<stepService-response>)))
  "Returns md5sum for a message object of type '<stepService-response>"
  "eddfa10760234970c83c5339187b1c40")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'stepService-response)))
  "Returns md5sum for a message object of type 'stepService-response"
  "eddfa10760234970c83c5339187b1c40")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<stepService-response>)))
  "Returns full string definition for message of type '<stepService-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'stepService-response)))
  "Returns full string definition for message of type 'stepService-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <stepService-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <stepService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'stepService-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'stepService)))
  'stepService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'stepService)))
  'stepService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'stepService)))
  "Returns string type for a service object of type '<stepService>"
  "gripper_pkg/stepService")