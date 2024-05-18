package component;

import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Cursor;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import pane.RootPane;

public class CreatePageButton extends StackPane {
	public CreatePageButton() {
		final Circle circle = new Circle(20, Color.LIGHTGRAY);
		final Text text = new Text("+");
		text.setFont(Font.font(20));
		setCursor(Cursor.HAND);
		setOnMouseClicked(new EventHandler<Event>() {
			@Override
			public void handle(Event e) {
				RootPane.getNavigationPane().addPage();
			}
		});
		getChildren().addAll(circle, text);
	}
}
