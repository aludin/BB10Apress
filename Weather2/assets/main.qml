import bb.cascades 1.0
TabbedPane {
    objectName: "tabbedPane"
    showTabsOnActionBar: true
    Tab {
        title: "City weather"
        Page {
            id: root
            Container {
                id: main
                layout: StackLayout {
                    orientation: LayoutOrientation.BottomToTop
                }
                TextField {
                    objectName: "location"
                    inputMode: TextFieldInputMode.Default
                    textStyle.textAlign: TextAlign.Center
                    input {
                        submitKey: SubmitKey.Go
                        submitKeyFocusBehavior: SubmitKeyFocusBehavior.Lose
                    }
                    hintText: "Enter city or country name"
                }
                Container {
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    topPadding: 100
                    Container {
                        Label {
                            objectName: "city"
                            //text: "Los Angeles"
                            horizontalAlignment: HorizontalAlignment.Center
                            textStyle {
                                fontWeight: FontWeight.W100
                                color: Color.Black
                                fontSize: FontSize.PercentageValue
                                fontSizeValue: 250
                            }
                        }
                        Label {
                            objectName: "state"
                            //text: "California"
                            horizontalAlignment: HorizontalAlignment.Center
                            textStyle {
                                fontWeight: FontWeight.W100
                                color: Color.Black
                                fontSize: FontSize.PercentageValue
                                fontSizeValue: 250
                            }
                        }
                        Label {
                            objectName: "temperature"
                            //text: "60.1 F (15.6 C)"
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
                                objectName: "weatherImage"
                                //imageSource: "asset:///images/clear.gif"
                                preferredWidth: 100
                                preferredHeight: 100
                                minHeight: 100
                                
                            }
                            Label {
                                objectName: "weather"
                                //text: "Clear"
                                verticalAlignment: VerticalAlignment.Center
                            }
                        }
                        Label {
                            objectName: "latitude"
                            //text: "latitude"
                            horizontalAlignment: HorizontalAlignment.Center
                            textStyle {
                                base: SystemDefaults.TextStyles.SubtitleText
                                fontWeight: FontWeight.W100
                                color: Color.Black
                            }
                        }
                        Label {
                            objectName: "longitude"
                            //text: "longitude"
                            horizontalAlignment: HorizontalAlignment.Center
                            textStyle {
                                base: SystemDefaults.TextStyles.SubtitleText
                                fontWeight: FontWeight.W100
                                color: Color.Black
                            }
                        }
                        Label {
                            objectName: "observationtime"
                            //text: "observationtime"
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

        }
    }
    Tab {
        title: "Map"
        Page {
            
            ScrollView {
                id: scrollview
                objectName: "scrollview"
                scrollViewProperties {
                    scrollMode: ScrollMode.Both
                    pinchToZoomEnabled: true  
                }
                ImageView {
                    id: citymap
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    objectName: "citymap"
                }
            }
            onCreationCompleted: {
                scrollview.zoomToPoint(320,220,2,ScrollAnimation.Smooth);
            }
        }
    }

}
