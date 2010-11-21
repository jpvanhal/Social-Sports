import Qt 4.7

Rectangle {
    width: 450
    height: 250
    TextEdit {
        id: "input"
        x: 10
        y: 10
        width: 100
        height: 200
        text: "command"
        cursorVisible: true
        wrapMode: TextEdit.WordWrap
    }
    Text {
        id: "output"
        x: 250
        y: 10
        width: 100
        height: 200
        text: "response"
    }
    Button {
        id: "send"
        label: "send"
        anchors.top: input.bottom
    }
}
