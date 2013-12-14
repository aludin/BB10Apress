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
    
    function onFinished(){
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
              if(value == SystemUiResult.CancelButtonSelection){
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
    Container {
        verticalAlignment: VerticalAlignment.Center
        horizontalAlignment: HorizontalAlignment.Center
        topPadding: 100
        ActivityIndicator {
                    id: activity
        } 
        Container {
            Label {
                id: city
                text: _app.weather.cityinfo.city
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    fontWeight: FontWeight.W100
                    color: Color.Black
                    fontSize: FontSize.PercentageValue
                    fontSizeValue: 250
                }
            }
            Label {
                id: state
                text: _app.weather.cityinfo.state
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    fontWeight: FontWeight.W100
                    color: Color.Black
                    fontSize: FontSize.PercentageValue
                    fontSizeValue: 250
                }
            }
            Label {
                id: temperature
                text: _app.weather.cityinfo.temperature
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    fontWeight: FontWeight.W100
                    color: Color.Black
                    fontSize: FontSize.PercentageValue
                    fontSizeValue: 250
                }
            }
            Container {
                horizontalAlignment: HorizontalAlignment.Center
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                ImageView {
                    id: weatherImage
                    image: _app.weather.cityinfo.weatherIcon
                    preferredWidth: 100
                    preferredHeight: 100
                    minHeight: 100

                }
                Label {
                    id: weather
                    text: _app.weather.cityinfo.weather
                    verticalAlignment: VerticalAlignment.Center
                }
            }
            Label {
                id: latitude
                text: _app.weather.cityinfo.latitude
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    base: SystemDefaults.TextStyles.SubtitleText
                    fontWeight: FontWeight.W100
                    color: Color.Black
                }
            }
            Label {
                id: longitude
                text: _app.weather.cityinfo.longitude
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    base: SystemDefaults.TextStyles.SubtitleText
                    fontWeight: FontWeight.W100
                    color: Color.Black
                }
            }
            Label {
                id: observationtime
                text: _app.weather.cityinfo.lastObservation
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    base: SystemDefaults.TextStyles.SubtitleText
                    fontWeight: FontWeight.W100
                    color: Color.Black
                }
            }
            Label {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
            }
        }
    }
}
