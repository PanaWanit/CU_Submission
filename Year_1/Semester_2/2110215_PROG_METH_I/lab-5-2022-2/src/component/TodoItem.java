package component;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import pane.RootPane;

public class TodoItem extends HBox {
	public TodoItem(String value) {
		setSpacing(10);
		final Text text = new Text(value);
		text.setFont(Font.font(20));
		Button button = new Button("Delete");
		button.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent arg0) {
				RootPane.getDisplayPane().removeTodoItem(TodoItem.this);
			}
		});
		getChildren().addAll(text, button);
	}
}
