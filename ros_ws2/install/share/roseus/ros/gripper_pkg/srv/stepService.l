;; Auto-generated. Do not edit!


(when (boundp 'gripper_pkg::stepService)
  (if (not (find-package "GRIPPER_PKG"))
    (make-package "GRIPPER_PKG"))
  (shadow 'stepService (find-package "GRIPPER_PKG")))
(unless (find-package "GRIPPER_PKG::STEPSERVICE")
  (make-package "GRIPPER_PKG::STEPSERVICE"))
(unless (find-package "GRIPPER_PKG::STEPSERVICEREQUEST")
  (make-package "GRIPPER_PKG::STEPSERVICEREQUEST"))
(unless (find-package "GRIPPER_PKG::STEPSERVICERESPONSE")
  (make-package "GRIPPER_PKG::STEPSERVICERESPONSE"))

(in-package "ROS")





(defclass gripper_pkg::stepServiceRequest
  :super ros::object
  :slots (_distance _initialise _direction ))

(defmethod gripper_pkg::stepServiceRequest
  (:init
   (&key
    ((:distance __distance) 0.0)
    ((:initialise __initialise) nil)
    ((:direction __direction) nil)
    )
   (send-super :init)
   (setq _distance (float __distance))
   (setq _initialise __initialise)
   (setq _direction __direction)
   self)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:initialise
   (&optional __initialise)
   (if __initialise (setq _initialise __initialise)) _initialise)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:serialization-length
   ()
   (+
    ;; float32 _distance
    4
    ;; bool _initialise
    1
    ;; bool _direction
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _initialise
       (if _initialise (write-byte -1 s) (write-byte 0 s))
     ;; bool _direction
       (if _direction (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _distance
     (setq _distance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _initialise
     (setq _initialise (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _direction
     (setq _direction (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass gripper_pkg::stepServiceResponse
  :super ros::object
  :slots (_success ))

(defmethod gripper_pkg::stepServiceResponse
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

(defclass gripper_pkg::stepService
  :super ros::object
  :slots ())

(setf (get gripper_pkg::stepService :md5sum-) "eddfa10760234970c83c5339187b1c40")
(setf (get gripper_pkg::stepService :datatype-) "gripper_pkg/stepService")
(setf (get gripper_pkg::stepService :request) gripper_pkg::stepServiceRequest)
(setf (get gripper_pkg::stepService :response) gripper_pkg::stepServiceResponse)

(defmethod gripper_pkg::stepServiceRequest
  (:response () (instance gripper_pkg::stepServiceResponse :init)))

(setf (get gripper_pkg::stepServiceRequest :md5sum-) "eddfa10760234970c83c5339187b1c40")
(setf (get gripper_pkg::stepServiceRequest :datatype-) "gripper_pkg/stepServiceRequest")
(setf (get gripper_pkg::stepServiceRequest :definition-)
      "float32 distance
bool initialise
bool direction
---
bool success

")

(setf (get gripper_pkg::stepServiceResponse :md5sum-) "eddfa10760234970c83c5339187b1c40")
(setf (get gripper_pkg::stepServiceResponse :datatype-) "gripper_pkg/stepServiceResponse")
(setf (get gripper_pkg::stepServiceResponse :definition-)
      "float32 distance
bool initialise
bool direction
---
bool success

")



(provide :gripper_pkg/stepService "eddfa10760234970c83c5339187b1c40")


