package pane;

import javafx.scene.layout.BorderPane;

public class RootPane extends BorderPane {
    private static NavigationPane navigationPane;
    private static DisplayPane displayPane;
    private static InputPane inputPane;

    public RootPane() {
        navigationPane = new NavigationPane();
        displayPane = new DisplayPane();
        inputPane = new InputPane();
        navigationPane.addPage();
        setLeft(navigationPane);
        setCenter(displayPane);
        setBottom(inputPane);
    }

    public static NavigationPane getNavigationPane() {
        return navigationPane;
    }

    public static DisplayPane getDisplayPane() {
        return displayPane;
    }

    public static InputPane getInputPane() {
        return inputPane;
    }
}
