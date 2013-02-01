import Timeline 1.0
import QtQuick 1.1

Rectangle {
    id: timeline
    width: 1000
    height: 360
    color: "#111"
    border.color: "#000000"

    Rectangle {
        id: mediaColumn
        width: 150
        height: 311
        color: "lightgrey"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.top: menu.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5

        ListView {
            id : mediaList
            anchors.fill: parent
            model: myModel
            delegate:
                     Rectangle {
                        id: wrapper
                        clip : true
                        height : 40
                        anchors.left: parent.left
                        anchors.right : parent.right
                        color: wrapper.ListView.isCurrentItem ? "#222" : "#444"
                        border.color: "#000000"
                        Text {  id:listText
                                text: modelData.name
                                horizontalAlignment: Text.AlignRight
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.right : parent.right
                                anchors.rightMargin : 30
                                color: wrapper.ListView.isCurrentItem ? "white" : "#999"
                                }
                        ListView.onAdd: SequentialAnimation {
                            PropertyAction { property: "height"; value: 0 }
                            NumberAnimation { property: "height"; to: 80; duration: 250; easing.type: Easing.InOutQuad }
                        }

                        ListView.onRemove: SequentialAnimation {
                            PropertyAction { property: "ListView.delayRemove"; value: true }
                            NumberAnimation { property: "height"; to: 0; duration: 250; easing.type: Easing.InOutQuad }

                            // Make sure delayRemove is set back to false so that the item can be destroyed
                            PropertyAction { property: "ListView.delayRemove"; value: false }
                        }
                        MouseArea{  anchors.fill : parent;
                                    hoverEnabled: true
                                    onEntered: listText.color = "white"
                                    onExited : listText.color = wrapper.ListView.isCurrentItem ? "white" : "#999"

                                  }
                    }
            focus: true
        }
    }

    Rectangle {
        id: menu
        x: 0
        y: 0
        height: 34
        gradient: Gradient {
            GradientStop {
                position: 1
                color: "#444"
            }
            GradientStop {
                position: 0
                color: "#666"
            }
        }
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5




        Text {
            id: title
            x: 37
            y: 7
            width: 68
            height: 20
            text: qsTr("Timeline")
            z: 1
            color : "white"
            horizontalAlignment: Text.AlignHCenter
            style: Text.Normal
            font.bold: true
            verticalAlignment: Text.AlignBottom
            font.pixelSize: 18
        }

        Rectangle {
            id: resize
            x: 706
            y: 7
            width: 30
            height: 30
            radius: 2
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            gradient: Gradient {
                GradientStop {
                    position: 1
                    color: "#444"
                }
                GradientStop {
                    position: 0
                    color: "#666"
                }
            }
            MouseArea {
                id: mouse_areaResize
                hoverEnabled: true
                anchors.fill: parent
                onEntered:{
                    parent.border.width = 1;
                    parent.border.color = "lightgrey"}
                onExited:if(parent.state != "clicked"){parent.border.width = 0;}
                onClicked: parent.state == 'clicked' ? parent.state = "" : parent.state = 'clicked';
            }
            states: [
                    State {
                        name: "clicked"
                        PropertyChanges { target: parent;
                            border.width : 1;
                            border.color : "lightgrey" }
                    }
                ]
            Image {
                id: minusImage6
                x: 3
                y: 1
                anchors.fill: parent
                source: "blue-02.png"
                fillMode: Image.PreserveAspectCrop
            }
        }

        Rectangle {
            id: display2
            y: 7
            width: 30
            height: 30
            radius: 2
            anchors.left: display1.right
            anchors.leftMargin: 12
            anchors.verticalCenter: parent.verticalCenter
            gradient: Gradient {
                GradientStop {
                    position: 1
                    color: "#444"
                }
                GradientStop {
                    position: 0
                    color: "#666"
                }
            }
            states: [
                    State {
                        name: "clicked"
                        PropertyChanges { target: parent;
                            border.width : 1;
                            border.color : "lightgrey" }
                    }
                ]
            MouseArea {
                id: mouse_areaDisplay2
                hoverEnabled: true
                anchors.fill: parent
                onEntered:{
                    parent.border.width = 1;
                    parent.border.color = "lightgrey"}
                onExited:if(parent.state != "clicked"){parent.border.width = 0;}
                onClicked: parent.state == 'clicked' ? parent.state = "" : parent.state = 'clicked';
            }

            Image {
                id: minusImage5
                x: -8
                y: -9
                anchors.fill: parent
                source: "blue-02.png"
                fillMode: Image.PreserveAspectCrop
            }
        }

        Text {
            id: affichage
            x: 758
            y: 7
            width: 68
            height: 20
            text: "Affichage :"
            color: "#888"
            style: Text.Normal
            font.pixelSize: 12
            font.bold: false
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
        }

        Rectangle {
            id: display1
            y: 7
            width: 30
            height: 30
            radius: 2
            anchors.left: affichage.right
            anchors.leftMargin: 12
            anchors.verticalCenter: parent.verticalCenter
            gradient: Gradient {
                GradientStop {
                    position: 1
                    color: "#444"
                }
                GradientStop {
                    position: 0
                    color: "#666"
                }
            }
            states: [
                    State {
                        name: "clicked"
                        PropertyChanges { target: parent;
                            border.width : 1;
                            border.color : "lightgrey" }
                    }
                ]
            MouseArea {
                id: mouse_areaDisplay1
                hoverEnabled: true
                anchors.fill: parent
                onEntered:{
                    parent.border.width = 1;
                    parent.border.color = "lightgrey"}
                onExited:if(parent.state != "clicked"){parent.border.width = 0;}
                onClicked: parent.state == 'clicked' ? parent.state = "" : parent.state = 'clicked';
            }

            Image {
                id: minusImage4
                x: -3
                y: -6
                anchors.fill: parent
                source: "blue-02.png"
                fillMode: Image.PreserveAspectCrop
            }
        }

        Rectangle {
            id: plus
            x: 217
            y: 7
            width: 30
            height: 30
            radius: 2
            anchors.verticalCenter: parent.verticalCenter
            gradient: Gradient {
                GradientStop {
                    position: 1
                    color: "#444"
                }
                GradientStop {
                    position: 0
                    color: "#666"
                }
            }
            MouseArea {
                id: mouse_areaPlus
                hoverEnabled: true
                anchors.fill: parent
                onEntered:{
                    parent.border.width = 1;
                    parent.border.color = "lightgrey"}
                onExited:if(parent.state != "clicked"){parent.border.width = 0;}
               onClicked:
                   parent.state == 'clicked' ? parent.state = "" : parent.state = 'clicked';
            }
            states: [
                    State {
                        name: "clicked"
                        PropertyChanges { target: parent;
                            border.width : 1;
                            border.color : "lightgrey" }
                    }
                ]
            Image {
                id: minusImage1
                anchors.fill: parent
                source: "blue-23.png"
                fillMode: Image.PreserveAspectCrop
            }
        }

        Rectangle {
            id: bin
            y: 3
            width: 30
            height: 30
            radius: 2
            anchors.left: plus.right
            anchors.leftMargin: 12
            gradient: Gradient {
                GradientStop {
                    position: 1
                    color: "#444"
                }
                GradientStop {
                    position: 0
                    color: "#666"
                }
            }
            MouseArea {
                id: mouse_areaBin
                hoverEnabled: true
                anchors.fill: parent
                onEntered:{
                    parent.border.width = 1;
                    parent.border.color = "lightgrey"}
                onExited:if(parent.state != "clicked"){parent.border.width = 0;}
                onClicked: parent.state == 'clicked' ? parent.state = "" : parent.state = 'clicked';
            }
            states: [
                    State {
                        name: "clicked"
                        PropertyChanges { target: parent;
                            border.width : 1;
                            border.color : "lightgrey" }
                    }
                ]
            Image {
                id: minusImage7
                transformOrigin: Item.Center
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
                source: "blue-16.png"
            }
        }

        Rectangle {
            id: pencil
            y: 7
            width: 30
            height: 30
            radius: 2
            anchors.left: bin.right
            anchors.leftMargin: 12
            anchors.verticalCenter: parent.verticalCenter
            gradient: Gradient {
                GradientStop {
                    position: 1
                    color: "#444"
                }
                GradientStop {
                    position: 0
                    color: "#666"
                }
            }
            Image {
                id: minusImage2
                anchors.fill: parent
                source: "draw.png"
                fillMode: Image.PreserveAspectCrop
            }
            MouseArea {
                id: mouse_areaPencil
                hoverEnabled: true
                anchors.fill: parent
                onEntered:{parent.border.width = 1;parent.border.color = "lightgrey"}
                onExited:{if(parent.state != "draw_on"){parent.border.width = 0;} }
                onClicked: {
                    parent.state == 'draw_on' ? parent.state = "draw_off" : parent.state = 'draw_on';
                    /*if(parent.state == 'draw_off'){ Timeline.sendValues(slider.value);}*/
                }
            }
            states: [
                    State {
                        name: "draw_on"
                        PropertyChanges { target: parent;
                            border.width : 1;
                            border.color : "lightgrey";
                           }
                    }
                ]
        }

        Rectangle {
            id: camera
            y: 7
            width: 30
            height: 30
            radius: 2
            anchors.left: pencil.right
            anchors.leftMargin: 12
            anchors.verticalCenter: parent.verticalCenter
            gradient: Gradient {
                GradientStop {
                    position: 1
                    color: "#444"
                }
                GradientStop {
                    position: 0
                    color: "#666"
                }
            }
            MouseArea {
                id: mouse_areaCamera
                hoverEnabled: true
                anchors.fill: parent
                onEntered:{
                    parent.border.width = 1;
                    parent.border.color = "lightgrey"}
                onExited:if(parent.state != "clicked"){parent.border.width = 0;}
                onClicked: parent.state == 'clicked' ? parent.state = "" : parent.state = 'clicked';
            }
            states: [
                    State {
                        name: "clicked"
                        PropertyChanges { target: parent;
                            border.width : 1;
                            border.color : "lightgrey" }
                    }
                ]
            Image {
                id: minusImage3
                anchors.fill: parent
                source: "blue-10.png"
                fillMode: Image.PreserveAspectCrop
            }
        }





    }

    Rectangle {
        id: sliderColumn
        color: "lightgrey"
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: mediaColumn.right
        anchors.leftMargin: 2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.top: menu.bottom
        anchors.topMargin: 5

            ListView {
                id : trackList
                anchors.fill: parent
                model: myModel
                delegate:
                         Rectangle {
                            id: wrapperTrack
                            clip : true
                            height : 40
                            anchors.left: parent.left
                            anchors.right : parent.right
                            color : "#999"
                            border.color : "#000"
                            Column {
                                id: column1
                                width: 773
                                height: 311
                                anchors.right: column2.left
                                anchors.rightMargin: 0
                                anchors.bottom: parent.bottom
                                anchors.left: parent.left
                                anchors.top: parent.top
                                Slider{
                                    id : slider
                                    anchors.left : parent.left
                                    anchors.right : parent.right
                                    anchors.leftMargin : 12
                                    anchors.rightMargin : 12
                                    anchors.verticalCenter: parent.verticalCenter
                                    maximum : modelData.duration

                                    function getValue(x){
                                        if((Math.ceil((x*slider.maximum)/slider.width)-((x*slider.maximum)/slider.width))<= 0.5){
                                            return Math.ceil((x*slider.maximum)/slider.width);
                                        }else{
                                            return Math.floor((x*slider.maximum)/slider.width);
                                        }
                                    }

                                    MouseArea{
                                        id : sliderMouseArea
                                        hoverEnabled: true
                                        anchors.fill: parent

                                        onEntered:{
                                            //slider.spacing = 50;
                                            console.log("maximum : " +slider.maximum)
                                            if(pencil.state == "draw_on"){slider.value = slider.getValue(mouseX)
                                                Track.sendValues(slider.value)
                                            console.log("slider.value : " +slider.value)}
                                        }
                                    }
                                }

                            ListView.onAdd: SequentialAnimation {
                                PropertyAction { property: "height"; value: 0 }
                                NumberAnimation { property: "height"; to: 80; duration: 250; easing.type: Easing.InOutQuad }
                            }

                            ListView.onRemove: SequentialAnimation {
                                PropertyAction { property: "ListView.delayRemove"; value: true }
                                NumberAnimation { property: "height"; to: 0; duration: 250; easing.type: Easing.InOutQuad }

                                // Make sure delayRemove is set back to false so that the item can be destroyed
                                PropertyAction { property: "ListView.delayRemove"; value: false }
                            }

                        }
                            Column {
                                id: column2
                                width: 40
                                anchors.right: parent.right
                                anchors.rightMargin: 0
                                anchors.bottom: parent.bottom
                                anchors.top: parent.top
                                Text {  text: "check"
                                        color : "white"
                                        horizontalAlignment: Text.AlignRight
                                        anchors.verticalCenter: parent.verticalCenter
                                        anchors.right : parent.right
                                       }
                            }
            }
        }




    }
}
