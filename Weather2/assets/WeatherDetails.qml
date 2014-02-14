import bb.cascades 1.2
import bb.system 1.2
Container {
    id: main
    background: back.imagePaint
    function onError(message) {
        errorPrompt.title = message;
        errorPrompt.show();
    }

    function onMultipleCitiesFound(cities) {
        citiesDialog.clearList();
        for (var i = 0; i < cities.length; i ++) {
            citiesDialog.appendItem(cities[i]);
        }
        citiesDialog.show();
    }

    function onFinished() {
        progress.cancel();
    }

    onCreationCompleted: {
        _app.weather.multipleCitiesFound.connect(main.onMultipleCitiesFound);
        _app.weather.error.connect(main.onError);
        _app.weather.finished.connect(main.onFinished);
        progress.cancelButton.label = "Cancel";
        progress.confirmButton.label = "";
    }

    attachedObjects: [
        ImagePaintDefinition {
            id: back
            repeatPattern: RepeatPattern.XY
            imageSource: "asset:///images/background.jpg"
        },
        SystemListDialog {
            id: citiesDialog
            onFinished: {
                if (value == SystemUiResult.ConfirmButtonSelection) {
                    _app.weather.cityWeather(citiesDialog.selectedIndices[0]);
                    progress.show();
                }
            }
        },
        SystemPrompt {
            id: errorPrompt
            onFinished: {
                _app.weather.cityWeather(errorPrompt.inputFieldTextEntry());
                progress.show();
            }
        },
        SystemProgressDialog {
            id: progress
            title: "Retrieving city"
            onFinished: {
                if (value == SystemUiResult.CancelButtonSelection) {
                    _app.weather.cancel();
                }
            }
        }
    ]
    layout: StackLayout {
        orientation: LayoutOrientation.BottomToTop
    }
    TextField {
        id: location
        inputMode: TextFieldInputMode.Default
        textStyle.textAlign: TextAlign.Center
        input {
            submitKey: SubmitKey.Go
            submitKeyFocusBehavior: SubmitKeyFocusBehavior.Lose
            onSubmitted: {
                _app.weather.cityWeather(location.text);
                progress.show();
            }
        }
        hintText: "Enter city or country name"
    }
    City {
        
    }
}
