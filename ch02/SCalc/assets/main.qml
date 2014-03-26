import bb.cascades 1.2

import "parser.js" as JSParser
// creates one page with a label

Page {
    id: calculatorView

    function isNumber(n) {
        return ! isNaN(parseFloat(n)) && isFinite(n);
    }

    onCreationCompleted: {
    }

    Container {
        topPadding: 50
        leftPadding: 50
        rightPadding: 50
        bottomPadding: 50
        layout: StackLayout {
            orientation: LayoutOrientation.TopToBottom
        }
        background: back.imagePaint

        attachedObjects: [
            ImagePaintDefinition {
                id: back
                //repeatPattern: RepeatPattern.XY
                imageSource: "asset:///background.png"
            }
        ]

        TextArea {
            bottomMargin: 40
            id: display
            hintText: "Enter expression"
            textStyle {
                base: SystemDefaults.TextStyles.BigText
                color: Color.DarkBlue
            }
            layoutProperties: StackLayoutProperties {
                spaceQuota: 2
            }
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            bottomMargin: 10
            Button {
                id: leftpar
                text: "("
                signal newSymbol(string symbol)
                onClicked: {
                    display.text += "(";
                }
            }
            Button {
                id: rightpar
                text: ")"
                onClicked: {
                    display.text += ")";
                }
            }
            Button {
                id: leftArrow
                text: "\u2190"
                onClicked: {
                    display.text = display.text.substring(0, display.text.length - 1);
                }
            }
            Button {
                id: clear
                text: "C"
                onClicked: {
                    display.text = "";
                }
            }
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            bottomMargin: 10
            Button {
                id: square
                text: "x\u00B2"
                onClicked: {
                    display.text = JSParser.Parser.evaluate("("+display.text+")^2", "");
                }
            }
            Button {
                id: cube
                text: "x\u00B3"
                onClicked: {
                    display.text = JSParser.Parser.evaluate("("+display.text+")^3", "");
                }
            }
            Button {
                id: root
                text: "\u221a"
                onClicked: {
                    display.text = JSParser.Parser.evaluate("sqrt("+display.text+")", "");
                }
            }
            
            Button {
                id: oneoverx
                text: "1/x"
                onClicked: {
                    display.text = JSParser.Parser.evaluate("1/("+display.text+")", "");
                }
            }

        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            bottomMargin: 10
            Button {
                id: seven
                text: "7"
                onClicked: {
                    display.text = display.text + 7;
                }
            }
            Button {
                id: eight
                text: "8"
                onClicked: {
                    display.text = display.text + 8;
                }
            }
            Button {
                id: nine
                text: "9"
                onClicked: {
                    display.text = display.text + 9;
                }
            }
            Button {
                id: mult
                text: "\u00D7"
                onClicked: {
                    display.text = display.text + "*";
                }
            }
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            bottomMargin: 10
            Button {
                id: four
                text: "4"
                onClicked: {
                    display.text = display.text + 4;
                }
            }
            Button {
                id: five
                text: "5"
                onClicked: {
                    display.text = display.text + 5;
                }
            }
            Button {
                id: six
                text: "6"
                onClicked: {
                    display.text = display.text + 6;
                }
            }
            Button {
                id: div
                text: "\u00f7"
                onClicked: {
                    display.text = display.text + "/";
                }
            }
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            bottomMargin: 10
            Button {
                id: one
                text: "1"
                onClicked: {
                    display.text = display.text + 1;
                }
            }
            Button {
                id: two
                text: "2"
                onClicked: {
                    display.text = display.text + 2;
                }
            }
            Button {
                id: three
                text: "3"
                onClicked: {
                    display.text = display.text + 3;
                }
            }
            Button {
                id: minus
                text: "-"
                onClicked: {
                    display.text = display.text + "-";
                }
            }
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            bottomMargin: 10
            Button {
                id: zero
                text: "0"
                onClicked: {
                    display.text = display.text + 0;
                }
            }
            Button {
                id: dot
                text: "."
                onClicked: {
                    display.text = display.text + ".";
                }
            }
            Button {
                id: equal
                text: "="
                onClicked: {
                    display.text = JSParser.Parser.evaluate(display.text, "");
                }
            }
            Button {
                id: plus
                text: "+"
                onClicked: {
                    display.text = display.text + "+";
                }
            }
        }
    }
}
