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

public class PageButton extends StackPane {
	private Circle circle;
	public PageButton(int pageNumber) {
		Circle circle = new Circle(25, Color.LIGHTGRAY);
		final Text text = new Text(pageNumber+"");
		text.setFont(Font.font(25));
		this.circle = circle;
		setCursor(Cursor.HAND);
		RootPane.getNavigationPane().setCurrentPage(pageNumber);
		setOnMouseClicked(new EventHandler<Event>() {
			@Override
			public void handle(Event e) {
				RootPane.getNavigationPane().setCurrentPage(pageNumber);
			}
		});
		getChildren().addAll(circle, text);
	}
	public void setActive(boolean value) {
		if(value)
			circle.setFill(Color.WHITE);
		else
			circle.setFill(Color.LIGHTGRAY);
	}
}
