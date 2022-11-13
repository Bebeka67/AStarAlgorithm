import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: toolBarWindow
    x: _rootWindow.x - width
    
    property bool startBool: controlStart.checked
    property bool goalBool: controlGoal.checked
    property bool blockBool: controlBlock.checked
    property bool freeBool: controlClear.checked
    
    visible: true
    
    width: spinBoxRow.width + 10
    maximumWidth: width
    minimumWidth: width
    
    height: _rootWindow.height
    
    header: ToolBar {
        background:
            Rectangle {
            color: "white"
        }
        
        Column {
            
            padding: 5
            RowLayout {
                id: iddd
                ToolButton {
                    text: "View"
                    
                    onClicked: {
                        console.log(expandedMatrix)
                    }
                }
                ToolButton {
                    text: "Calculate"
                    
                    onClicked: appBackend.runAlgorithm();
                }
            }
            
            Rectangle {
                color: "black"
                width: toolBarWindow.width - parent.padding * 2
                height: 1
            }
            
            Grid {
                horizontalItemAlignment: Grid.AlignHCenter
                verticalItemAlignment: Grid.AlignVCenter
                
                columns: 4
                rows: 2
                Label {
                    text: "Start"
                    color: "Green"
                }
                Label {
                    text: "Goal"
                    color: "blue"
                }
                Label {
                    text: "Block"
                    color: "black"
                }
                Label {
                    text: "Clear"
                    color: "darkGray"
                }
                
                RadioButton {
                    id: controlStart
                    checked: true
                    
                    indicator: Rectangle {
                        id: shell
                        implicitWidth: 30
                        implicitHeight: 30
                        x: controlStart.leftPadding
                        y: parent.height / 2 - height / 2
                        radius: 15
                        border.color: "lightgray"
                        Rectangle {
                            anchors.verticalCenter: shell.verticalCenter
                            anchors.horizontalCenter: shell.horizontalCenter
                            width: 20
                            height: 20
                            radius: 10
                            color: "green"
                            visible: controlStart.checked
                        }
                    }
                }
                RadioButton {
                    id: controlGoal
                    
                    indicator: Rectangle {
                        implicitWidth: 30
                        implicitHeight: 30
                        x: controlGoal.leftPadding
                        y: parent.height / 2 - height / 2
                        radius: 15
                        border.color: "lightgray"
                        
                        Rectangle {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: 20
                            height: 20
                            radius: 10
                            color: "Blue"
                            visible: controlGoal.checked
                        }
                    }
                }
                RadioButton {
                    id: controlBlock
                    
                    indicator: Rectangle {
                        implicitWidth: 30
                        implicitHeight: 30
                        x: controlBlock.leftPadding
                        y: parent.height / 2 - height / 2
                        radius: 15
                        border.color: "lightgray"
                        
                        Rectangle {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: 20
                            height: 20
                            radius: 10
                            color: "black"
                            visible: controlBlock.checked
                        }
                    }
                }
                RadioButton {
                    id: controlClear
                    
                    indicator: Rectangle {
                        implicitWidth: 30
                        implicitHeight: 30
                        x: controlClear.leftPadding
                        y: parent.height / 2 - height / 2
                        radius: 15
                        border.color: "lightgray"
                        
                        Rectangle {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: 20
                            height: 20
                            radius: 10
                            color: "lightgray"
                            visible: controlClear.checked
                        }
                    }
                }
                
            }
        }
    }
    
    Column {
        padding: 5
        Row {
            id: spinBoxRow
            
            SpinBox {
                id: rows
                from: 1
                value: matrixRows
                onValueChanged: mediator.row = value
                editable: true
            }
            
            SpinBox {
                id: columns
                from:1
                value: matrixColumns
                
                onValueChanged: mediator.column = value
                editable: true
            }
        }
    }
}
