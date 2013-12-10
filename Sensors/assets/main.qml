import bb.cascades 1.2
Page {
    Container {
        leftPadding: 10
        rightPadding: 10
        Label {
            text: "Hello Sensors"
            textStyle.base: SystemDefaults.TextStyles.BigText
            horizontalAlignment: HorizontalAlignment.Center
        }
        Container {
            bottomMargin: 50
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Label {
                text: "Accel x:"
                verticalAlignment: VerticalAlignment.Center
            }
            TextField {
                text: _app.sensor.accelX
            }

        }
        Container {
            bottomMargin: 50
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Label {
                text: "Accel y:"
                verticalAlignment: VerticalAlignment.Center
            }
            TextField {
                text: _app.sensor.accelY
            }
        }
        Container {
            bottomMargin: 50
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Label {
                text: "Accel z:"
                verticalAlignment: VerticalAlignment.Center
            }
            TextField {
                text: _app.sensor.accelZ
            }
        }
        Container {
            bottomMargin: 50

            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Label {
                text: "Light    :"
                verticalAlignment: VerticalAlignment.Center
            }
            TextField {
                id: light
                text: _app.sensor.lux
            }
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            horizontalAlignment: HorizontalAlignment.Center
            Button {
                text: "start"
                onClicked: {
                    _app.sensor.start();
                }
            }
            Button {
                text: "stop"
                onClicked: {
                    _app.sensor.stop();
                }
            }
        }
    }
}
