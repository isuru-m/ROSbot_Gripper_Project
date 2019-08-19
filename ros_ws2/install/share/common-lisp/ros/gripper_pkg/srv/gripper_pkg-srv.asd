
(cl:in-package :asdf)

(defsystem "gripper_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "servoService" :depends-on ("_package_servoService"))
    (:file "_package_servoService" :depends-on ("_package"))
    (:file "stepService" :depends-on ("_package_stepService"))
    (:file "_package_stepService" :depends-on ("_package"))
  ))