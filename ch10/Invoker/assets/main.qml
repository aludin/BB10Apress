import bb.cascades 1.2
import bb.cascades.pickers 1.0
import com.ludin.utils 1.0
Page {
    Container {
        leftPadding: 10
        rightPadding: 10
        topPadding: 10
        bottomPadding: 10
        Button {
            text: "Invoke Picture Viewer"
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                filePicker.open();
            }
        }
        Button {
            text: "Invoke Browser"
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                appInvoker.openBrowser("http://www.apress.com");
            }
        }
        Button {
            text: "Create Calendar Event"
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                var participants = [ "aludin@riskcetera.com", "jsmith@riskcetera.com" ];
                appInvoker.createEvent("Ride", "Specs for the R cloud editor", participants);
            }
        }
        Button {
            text: "Take Picture"
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                appInvoker.takePicture();
            }
        }
        Button {
            text: "Invoke com.riskcetera.card.previewer"
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                appInvoker.invokeTargetWithUri("com.riskcetera.card.previewer", "bb.action.VIEW", "file:///accounts/1000/shared/photos/leevancleef.jpg")
            }
        }
        Button {
            text: "Invoke com.riskcetera.card.picker"
            horizontalAlignment: HorizontalAlignment.Fill
            onClicked: {
                appInvoker.invokeTargetWithUri("com.riskcetera.card.picker", "bb.action.VIEW", "file:///accounts/1000/shared/photos/leevancleef.jpg")
            }
        }
        attachedObjects: [
            AppInvoker {
                id: appInvoker
                onTargetsChanged: {
                    for (var i = 0; i < appInvoker.targets.length; i ++) {
                        var targetId = appInvoker.targets[i];
                        console.log(targetId);
                    }
                }
            },
            FilePicker {
                id: filePicker
                type: FileType.Picture
                title: "Select Picture"
                directories: [ "/accounts/1000/shared/photos" ]
                onFileSelected: {
                    //make sure to prepend "file://"
                    appInvoker.viewImage("file://" + selectedFiles[0]);
                }
            }
        ]
    }
}
