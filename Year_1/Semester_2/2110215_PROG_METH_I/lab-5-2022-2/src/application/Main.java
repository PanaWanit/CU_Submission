package application;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import pane.RootPane;

public class Main extends Application {

    @Override
    public void start(Stage stage) {
        RootPane root = new RootPane();
        Scene scene = new Scene(root, 800, 640);
        stage.setTitle("SIMPLE(?) TO DO LISTS");
        stage.setScene(scene);
        stage.setResizable(false);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}
