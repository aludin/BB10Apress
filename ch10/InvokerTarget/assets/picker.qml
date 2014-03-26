import bb.cascades 1.2

Page {
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        leftPadding: 10
        ImageButton {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Center
            id: eastwood
            defaultImageSource: "file:///accounts/1000/shared/photos/jackpalance.jpg"
            preferredWidth: 300
            preferredHeight: 300
            onClicked: {
                _app.onPickDone(eastwood.defaultImageSource.toString());
            }
        }
        ImageButton {
            topMargin: 10
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Center
            id: palance
            defaultImageSource: "file:///accounts/1000/shared/photos/leevancleef.jpg"
            preferredWidth: 300
            preferredHeight: 300
            onClicked: {
                _app.onPickDone(palance.defaultImageSource.toString());
            }
        }

    }
}
