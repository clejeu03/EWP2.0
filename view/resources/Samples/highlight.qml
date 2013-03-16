import QtQuick 2.0

Rectangle {
    width: 200; height: 300

    // Define a delegate component.  A component will be
    // instantiated for each visible item in the list.
    Component {
        id: delegate
        Item {
            id: wrapper
            width: 200; height: 55
            Column {
                SmallText { text: 'Name: ' + name }
                SmallText { text: 'Type: ' + type }
                SmallText { text: 'Age: ' + age }
            }
            // indent the item if it is the current item
            states: State {
                name: "Current"
                when: wrapper.ListView.isCurrentItem
                PropertyChanges { target: wrapper; x: 20 }
            }
            transitions: Transition {
                NumberAnimation { properties: "x"; duration: 200 }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: wrapper.ListView.view.currentIndex = index
            }
        }
    }

    // Define a highlight with customized movement between items.
    Component {
        id: highlightBar
        Rectangle {
            width: 200; height: 50
            color: "#FFFF88"
            y: listView.currentItem.y;
            Behavior on y { SpringAnimation { spring: 2; damping: 0.1 } }
        }
    }

    ListView {
        id: listView
        width: 200; height: parent.height
        x: 30

        model: MyModel {}
        delegate: delegate
        focus: true

        // Set the highlight delegate. Note we must also set highlightFollowsCurrentItem
        // to false so the highlight delegate can control how the highlight is moved.
        highlight: highlightBar
        highlightFollowsCurrentItem: false
    }
}
