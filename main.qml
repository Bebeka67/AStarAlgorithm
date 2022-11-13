import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    id: _rootWindow
    visible: true
    width: 640
    height: 480
    x: Screen.width + (screenWidth - width) / 2
    y: (screenHeight - height) / 2

    property int screenWidth: Screen.desktopAvailableWidth - Screen.width
    property int screenHeight: Screen.desktopAvailableHeight

    property var mediator: appBackend

    property var expandedMatrix: appBackend.expandedMatrix

    property int matrixColumns: mediator.column
    property int matrixRows: mediator.row

    property color blockedColor: "black"
    property color freeColor: "white"
    property color openListColor: "green"
    property color closedListColor: "red"


    function currentColor()
    {
        if(_toolBarWindow.startBool)
            return 1
        if(_toolBarWindow.goalBool)
            return 9
        if(_toolBarWindow.blockBool)
            return -1
        if(_toolBarWindow.freeBool)
            return 0
    }


    function setColor(value)
    {
        if(value === 0)
            return "white"
        if(value === 1 || value === 6)
            return "green"
        if(value === -1)
            return "orange"
        if(value === 9 || value === 14)
            return "blue"
        if(value === 5)
            return "red"
    }

    function viewItems()
    {
        console.error("he")
        for(var i = 0; i < repeater.count; i++ )
        {
            var data = repeater.itemAt(i)
            logInfo.text += data.contentText
            logInfo.text += " "
            console.log(data.color)
         }
    }

    function showExpMtrx()
    {   //for(var i = 0; i < matrixColumns*matrixRows; i++)
        console.log(expandedMatrix)
    }

    ToolBarWindow {
        id: _toolBarWindow
        y: _rootWindow.y
    }





    Grid {
        id: matrixView
        anchors.centerIn: parent
        rows: matrixRows
        columns: matrixColumns


        columnSpacing: 1
        rowSpacing: 1

        Repeater {
            id: repeater
            model: expandedMatrix //parent.rows * parent.columns

            Rectangle {
                width: 60; height: 60
                color: setColor(modelData)//"white"
                border.color: "black"
                border.width: 3

                property string contentText: model.index        // model.index

                Label {

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter

                    text: parent.contentText
                    color: "black"

                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        expandedMatrix[model.index] = currentColor()
                        appBackend.setExpandedMatrix(expandedMatrix);
                        //color == freeColor ? color = blockedColor : color = freeColor
                    }
                        //onParentChanged: (color !== freeColor && color != blockedColor) ? enabled = 0 : enabled = 1
                }
            }
        }
    }


}
