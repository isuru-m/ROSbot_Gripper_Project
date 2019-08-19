;; Auto-generated. Do not edit!


(when (boundp 'gripper_pkg::stepActionGoal)
  (if (not (find-package "GRIPPER_PKG"))
    (make-package "GRIPPER_PKG"))
  (shadow 'stepActionGoal (find-package "GRIPPER_PKG")))
(unless (find-package "GRIPPER_PKG::STEPACTIONGOAL")
  (make-package "GRIPPER_PKG::STEPACTIONGOAL"))

(in-package "ROS")
;;//! \htmlinclude stepActionGoal.msg.html


(defclass gripper_pkg::stepActionGoal
  :super ros::object
  :slots (_distance _direction _initialise ))

(defmethod gripper_pkg::stepActionGoal
  (:init
   (&key
    ((:distance __distance) 0.0)
    ((:direction __direction) nil)
    ((:initialise __initialise) nil)
    )
   (send-super :init)
   (setq _distance (float __distance))
   (setq _direction __direction)
   (setq _initialise __initialise)
   self)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:initialise
   (&optional __initialise)
   (if __initialise (setq _initialise __initialise)) _initialise)
  (:serialization-length
   ()
   (+
    ;; float32 _distance
    4
    ;; bool _direction
    1
    ;; bool _initialise
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _direction
       (if _direction (write-byte -1 s) (write-byte 0 s))
     ;; bool _initialise
       (if _initialise (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _distance
     (setq _distance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _direction
     (setq _direction (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _initialise
     (setq _initialise (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get gripper_pkg::stepActionGoal :md5sum-) "310977177aeb6144200c4906d67a11ee")
(setf (get gripper_pkg::stepActionGoal :datatype-) "gripper_pkg/stepActionGoal")
(setf (get gripper_pkg::stepActionGoal :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
# Define the goal
float32 distance # distance to move the stepper
bool direction
bool initialise 

")



(provide :gripper_pkg/stepActionGoal "310977177aeb6144200c4906d67a11ee")

