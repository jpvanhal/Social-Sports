import Qt 4.7

Rectangle {
    id: button
    height: 25
    width: 60

    property color buttonColor: "lightblue"
    property color onHoverColor: "gold"
    property color borderColor: "white"
    property string label: "button"

    Text {
        id: buttonLabel
        text: parent.label
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    signal buttonClick()
    onButtonClick: {
        console.log("button clicked" )
    }

    MouseArea{
        onClicked: buttonClick()
        hoverEnabled: true
        onEntered: parent.border.color = onHoverColor
        onExited:  parent.border.color = borderColor
        anchors.fill: parent
    }
}
