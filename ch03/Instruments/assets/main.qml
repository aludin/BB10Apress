import bb.cascades 1.2
import ludin.instruments 1.0

Page {
    Container {
        //Todo: fill me with QML
        Label {
            // Localized text with the dynamic translation and locale updates support
            text: "Option Pricer"
            horizontalAlignment: HorizontalAlignment.Center
            textStyle.base: SystemDefaults.TextStyles.BigText
        }
        TextField {
            id: spotField
            hintText: "Enter spot price"
        }
        TextField {
            id: strikeField
            hintText: "Enter strike price"
        }
        TextField {
            id: maturityField
            hintText: "Enter time to maturity"
        }
        TextField {
            id: volatilityField
            hintText: "Enter underlying volatility"
        }
        TextField {
            id: riskfreeRateField
            hintText: "Enter risk free rate"
        }
        Label {
            text: "Option fair price"
            horizontalAlignment: HorizontalAlignment.Center
        }
        TextField {
            id: priceField
            text: option.price
        }
        attachedObjects: [
            OptionType {
                id: option
                type: OptionType.CALL
                symbol: "myoption"
                spot: spotField.text
                strike: strikeField.text
                maturity: maturityField.text
                volatility: volatilityField.text
                riskfreeRate: riskfreeRateField.text
            }
        ]
    }
}
