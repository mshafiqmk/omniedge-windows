import QtQuick 2.0
import QtQuick.Controls 2.3

Page {
    id: loginPage
    width: 450*2/3
    height: 810*2/3
    Image {
        x: 165
        y: 189
        width: 120
        height: 120
        anchors.verticalCenterOffset: -150
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        source: "./images/logo.jpeg"
    }

    Item{
        id:item_auth
        objectName: "item_auth"
        signal googleAuthClicked()
        anchors.verticalCenterOffset: 80
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Image {
            id: image
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            source: "./images/Sign.png"
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                   console.info("image clicked!")
                    item_auth.googleAuthClicked()
                    connectForm.visible = true
                    loginForm.visible = false

                }
            }
        }
    }
    Text {
        id: textAppName
        text: qsTr("OmniEdge")
        anchors.verticalCenterOffset: -60
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        renderType: Text.NativeRendering
        font.pixelSize: 24
        font.bold: true
        font.family: "Segoe UI"
    }
    Text {
        id: textSlogan
        text: qsTr("Connect without concern")
        anchors.verticalCenterOffset: -30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 16
        font.family: "Segoe UI"
    }
}
