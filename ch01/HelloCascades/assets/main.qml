import bb.cascades 1.0

Page {
    Container {
        //Todo: fill me with QML
        Label {
            id: helloCascades
            // Localized text with the dynamic translation and locale updates support
            textStyle.base: SystemDefaults.TextStyles.BigText
            text: "Hello Cascades"
            horizontalAlignment: HorizontalAlignment.Center
        }
        Container {
            id: imageContainer
            horizontalAlignment: HorizontalAlignment.Center
            layout: DockLayout {

            }
            ImageView {
                id: swissalpsday
                imageSource: "asset:///images/swissalpsday.png"

            }
            ImageView {
                id: swissalpsnight
                imageSource: "asset:///images/swissalpsnight.png"
            }
        }
        Slider {
            horizontalAlignment: HorizontalAlignment.Center
            onImmediateValueChanged: {
                swissalpsnight.opacity = immediateValue
            }
        }
    }
}
