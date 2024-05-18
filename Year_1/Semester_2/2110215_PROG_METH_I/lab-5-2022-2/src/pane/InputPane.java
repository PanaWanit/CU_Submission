package pane;

import component.TodoItem;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;

public class InputPane extends HBox {
    public InputPane() {
        setPrefHeight(70);
        setBackground(new Background( new BackgroundFill(Color.LIGHTBLUE, null, null) ));
        setSpacing(20);
        setAlignment(Pos.CENTER);
        final TextField textField = new TextField();
        textField.setPrefWidth(300);
        final Button btn = new Button("Submit");
        btn.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent arg0) {
				if(textField.getText().isEmpty())
					return;
				TodoItem todoItem = new TodoItem(textField.getText());
				RootPane.getDisplayPane().addTodoItem(todoItem);
				textField.clear();
			}
		});
        getChildren().addAll(textField, btn);
    }
}
