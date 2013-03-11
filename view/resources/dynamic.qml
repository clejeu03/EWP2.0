import QtQuick 1.0

// This example shows how items can be dynamically added to and removed from
// a ListModel, and how these list modifications can be animated.

Rectangle {
    id: container
    width: 500; height: 400
    color: "#343434"

    // The model:
    ListModel {
        id: fruitModel

        ListElement {
            name: "Apple"; cost: 2.45
            attributes: [
                ListElement { description: "Core" },
                ListElement { description: "Deciduous" }
            ]
        }
        ListElement {
            name: "Banana"; cost: 1.95
            attributes: [
                ListElement { description: "Tropical" },
                ListElement { description: "Seedless" }
            ]
        }
        ListElement {
            name: "Cumquat"; cost: 3.25
            attributes: [
                ListElement { description: "Citrus" }
            ]
        }
        ListElement {
            name: "Durian"; cost: 9.95
            attributes: [
                ListElement { description: "Tropical" },
                ListElement { description: "Smelly" }
            ]
        }
    }

    // The delegate for each fruit in the model:
    Component {
        id: listDelegate
//! [0]
        Item {
//! [0]
            id: delegateItem
            width: listView.width; height: 80
            clip: true

            Column {
                id: arrows
                anchors {
                    left: parent.left
                    verticalCenter: parent.verticalCenter
                }
                Image {
                    source: "blue-02.png"
                    MouseArea { anchors.fill: parent; onClicked: fruitModel.move(index, index-1, 1) }
                }
                Image { source: "blue-02.png"
                    MouseArea { anchors.fill: parent; onClicked: fruitModel.move(index, index+1, 1) }
                }
            }

            Column {
                anchors {
                    left: arrows.right
                    horizontalCenter: parent.horizontalCenter;
                    bottom: parent.verticalCenter
                }

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: name
                    font.pixelSize: 15
                    color: "white"
                }
                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 5
                    Repeater {
                        model: attributes
                        Text { text: description; color: "White" }
                    }
                }
            }

            Item {
                anchors {
                    left: arrows.right
                    horizontalCenter: parent.horizontalCenter;
                    top: parent.verticalCenter
                    bottom: parent.bottom
                }

                Row {
                    anchors.centerIn: parent
                    spacing: 10

                    Image {
                        anchors.verticalCenter: parent.verticalCenter
                        source: "blue-02.png"
                        MouseArea{anchors.fill:parent; onClicked: fruitModel.setProperty(index, "cost", cost + 0.25)}
                    }

                    Text {
                        id: costText
                        anchors.verticalCenter: parent.verticalCenter
                        text: '$' + Number(cost).toFixed(2)
                        font.pixelSize: 15
                        color: "white"
                        font.bold: true
                    }

                    Image {
                        anchors.verticalCenter: parent.verticalCenter
                        source: "blue-02.png"
                        MouseArea{anchors.fill:parent; onClicked: fruitModel.setProperty(index, "cost", Math.max(0,cost-0.25))}
                    }

                    Image {
                        source: "blue-02.png"
                        MouseArea { anchors.fill:parent; onClicked: fruitModel.remove(index) }
                    }
                }
            }

            // Animate adding and removing of items:
//! [1]
            ListView.onAdd: SequentialAnimation {
                PropertyAction { target: delegateItem; property: "height"; value: 0 }
                NumberAnimation { target: delegateItem; property: "height"; to: 80; duration: 250; easing.type: Easing.InOutQuad }
            }

            ListView.onRemove: SequentialAnimation {
                PropertyAction { target: delegateItem; property: "ListView.delayRemove"; value: true }
                NumberAnimation { target: delegateItem; property: "height"; to: 0; duration: 250; easing.type: Easing.InOutQuad }

                // Make sure delayRemove is set back to false so that the item can be destroyed
                PropertyAction { target: delegateItem; property: "ListView.delayRemove"; value: false }
            }
        }
//! [1]
    }

    // The view:
    ListView {
        id: listView
        anchors {
            left: parent.left; top: parent.top;
            right: parent.right; bottom: buttons.top;
            margins: 20
        }
        model: fruitModel
        delegate: listDelegate
    }

    Row {
        id: buttons
        anchors { left: parent.left; bottom: parent.bottom; margins: 20 }
        spacing: 10

        Text {
            text: "Add an item"
            MouseArea{onClicked: {
                fruitModel.append({
                    "name": "Pizza Margarita",
                    "cost": 5.95,
                    "attributes": [{"description": "Cheese"}, {"description": "Tomato"}]
                })}
            }
        }

        Text {
            text: "Remove all items"
            MouseArea{anchors.fill:parent; onClicked: fruitModel.clear()}
        }
    }
}
