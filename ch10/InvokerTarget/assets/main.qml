import bb.cascades 1.2
import bb.cascades.pickers 1.0

Page {
    Container {
        leftPadding: 10
        rightPadding: 10
        topPadding: 10
        bottomPadding: 10
        Button {
            text: "Choose picture"
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                filePicker.open();
            }
        }
        ImageView {
            id: imageview
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            
            imageSource: _app.uri
            scalingMethod: ScalingMethod.AspectFit
        }
    }
    attachedObjects: [
        FilePicker {
            id: filePicker
            type: FileType.Picture
            title: "Select Picture"
            directories: [ "/accounts/1000/shared/photos" ]
            onFileSelected: {
                //make sure to prepend "file://" when using as a source for an ImageView or MediaPlayer
                imageview.imageSource = "file://" + selectedFiles[0];
            }
        }
    ]

}
