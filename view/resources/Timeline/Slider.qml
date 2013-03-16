import QtQuick 1.0

 Item {
     id: slider; height: 16

     // value is read/write.
     property real value: 0
     property real spacing: 20
     onValueChanged: updatePos();
     property real maximum: 100
     property real minimum: 1
     property int xMax: width - handle1.width - 4
     onXMaxChanged: updatePos();
     onMinimumChanged: updatePos();

     function updatePos() {
         if (maximum > minimum) {
             var pos = 2 + (value - minimum) * slider.xMax / (maximum - minimum);
             pos = Math.min(pos, width - handle1.width - 2);
             pos = Math.max(pos, 2);
             handle1.x = pos - spacing;
             handle2.x = pos + spacing;
         } else {
             handle1.x = 2;
             handle2.x = 2 + spacing/2;
         }
     }


     Rectangle {
         anchors.fill: parent
         border.color: "white"; border.width: 0; radius: 2
         gradient: Gradient {
             GradientStop { position: 0.0; color: "#66343434" }
             GradientStop { position: 1.0; color: "#66000000" }
         }
     }

     Rectangle {
         id: handle1; smooth: true
         x : value1;y: 2; width : 10; height : slider.height-4; radius: 2
         gradient: Gradient {
             GradientStop { position: 0.0; color: "lightgray" }
             GradientStop { position: 1.0; color: "gray" }
         }
         Behavior on x { PropertyAnimation { duration: 500; easing.type:Easing.OutExpo } }
         Behavior on state { PropertyAnimation { duration: 500; easing.type:Easing.OutExpo } }
         opacity : value != 0 ? 100 : 0;
         /*MouseArea {
             id: mouse1
             anchors.fill: parent; drag.target: parent
             drag.axis: Drag.XAxis; drag.minimumX: 2; drag.maximumX: slider.xMax+2
             onPositionChanged: { value1 = (maximum - minimum) * (handle1.x-2) / slider.xMax + minimum; }
         }*/
     }
     Rectangle {
         id: handle2; smooth: true ;
         x: value2; y: 2;width : 10; height : slider.height-4; radius: 2;
         gradient: Gradient {
             GradientStop { position: 0.0; color: "lightgray" }
             GradientStop { position: 1.0; color: "gray" }

         }
         opacity: value != 0 ?  100 : 0;
         Behavior on x { PropertyAnimation { duration: 500; easing.type:Easing.OutExpo } }
         Behavior on opacity { PropertyAnimation { duration: 500; easing.type:Easing.OutExpo } }
         /*MouseArea {
             id: mouse2
             anchors.fill: parent; drag.target: parent
             drag.axis: Drag.XAxis; drag.minimumX: 2; drag.maximumX: slider.xMax+2
             onPositionChanged: { value2 = (maximum - minimum) * (handle2.x-2) / slider.xMax + minimum; }
         }*/
     }
 }
