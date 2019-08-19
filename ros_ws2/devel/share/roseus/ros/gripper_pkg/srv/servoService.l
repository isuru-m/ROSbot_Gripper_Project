;; Auto-generated. Do not edit!


(when (boundp 'gripper_pkg::servoService)
  (if (not (find-package "GRIPPER_PKG"))
    (make-package "GRIPPER_PKG"))
  (shadow 'servoService (find-package "GRIPPER_PKG")))
(unless (find-package "GRIPPER_PKG::SERVOSERVICE")
  (make-package "GRIPPER_PKG::SERVOSERVICE"))
(unless (find-package "GRIPPER_PKG::SERVOSERVICEREQUEST")
  (make-package "GRIPPER_PKG::SERVOSERVICEREQUEST"))
(unless (find-package "GRIPPER_PKG::SERVOSERVICERESPONSE")
  (make-package "GRIPPER_PKG::SERVOSERVICERESPONSE"))

(in-package "ROS")





(defclass gripper_pkg::servoServiceRequest
  :super ros::object
  :slots (_radius ))

(defmethod gripper_pkg::servoServiceRequest
  (:init
   (&key
    ((:radius __radius) 0.0)
    )
   (send-super :init)
   (setq _radius (float __radius))
   self)
  (:radius
   (&optional __radius)
   (if __radius (setq _radius __radius)) _radius)
  (:serialization-length
   ()
   (+
    ;; float32 _radius
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _radius
       (sys::poke _radius (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _radius
     (setq _radius (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass gripper_pkg::servoServiceResponse
  :super ros::object
  :slots (_success ))

(defmethod gripper_pkg::servoServiceResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass gripper_pkg::servoService
  :super ros::object
  :slots ())

(setf (get gripper_pkg::servoService :md5sum-) "397e5d9373b2d6be3b1e90928218304b")
(setf (get gripper_pkg::servoService :datatype-) "gripper_pkg/servoService")
(setf (get gripper_pkg::servoService :request) gripper_pkg::servoServiceRequest)
(setf (get gripper_pkg::servoService :response) gripper_pkg::servoServiceResponse)

(defmethod gripper_pkg::servoServiceRequest
  (:response () (instance gripper_pkg::servoServiceResponse :init)))

(setf (get gripper_pkg::servoServiceRequest :md5sum-) "397e5d9373b2d6be3b1e90928218304b")
(setf (get gripper_pkg::servoServiceRequest :datatype-) "gripper_pkg/servoServiceRequest")
(setf (get gripper_pkg::servoServiceRequest :definition-)
      "float32 radius
---
bool success

")

(setf (get gripper_pkg::servoServiceResponse :md5sum-) "397e5d9373b2d6be3b1e90928218304b")
(setf (get gripper_pkg::servoServiceResponse :datatype-) "gripper_pkg/servoServiceResponse")
(setf (get gripper_pkg::servoServiceResponse :definition-)
      "float32 radius
---
bool success

")



(provide :gripper_pkg/servoService "397e5d9373b2d6be3b1e90928218304b")


