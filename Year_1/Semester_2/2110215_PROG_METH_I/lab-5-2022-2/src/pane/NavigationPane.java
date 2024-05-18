package pane;

import component.CreatePageButton;
import component.PageButton;
import javafx.geometry.Insets;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;

import java.util.ArrayList;

public class NavigationPane extends VBox {
	private final ArrayList<PageButton> pageButtons = new ArrayList<>();
	private int currentPage;

	public NavigationPane() {
		this.setPrefWidth(80);
		this.setBackground(new Background(new BackgroundFill(Color.GRAY, null, null)));
		this.setSpacing(15);
		this.setPadding(new Insets(15));

		CreatePageButton createPageButton = new CreatePageButton();
		this.getChildren().add(createPageButton);
	}

	public void addPage() {
		PageButton pageButton = new PageButton(pageButtons.size());
		pageButtons.add(pageButton);
		getChildren().add(pageButtons.size()-1, pageButton);
		RootPane.getDisplayPane().addTodoList();
		setCurrentPage(pageButtons.size()-1);
	}

	public int getCurrentPage() {
		return this.currentPage;
	}

	public void setCurrentPage(int pageNumber) {
    	if(pageNumber < 0 || pageNumber > pageButtons.size()-1)
    		return;
    	PageButton btn = pageButtons.get(this.currentPage);
    	btn.setActive(false);
        this.currentPage = pageNumber;
        btn = pageButtons.get(this.currentPage);
        btn.setActive(true);
        RootPane.getDisplayPane().setActiveTodoList(this.currentPage);
    }
}
