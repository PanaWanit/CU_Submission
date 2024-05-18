package logic.card;

import logic.game.CardSymbol;
import logic.game.CardColor;

//You CAN modify the first line
abstract public class BaseCard {

	private CardColor color;
	private CardSymbol symbol;
	public BaseCard(CardColor color, CardSymbol symbol) {
		setColor(color);
		setSymbol(symbol);
	}
	abstract public String toString();
	abstract public boolean canPlay();
	abstract public String play();
	
	public CardColor getColor() {
		return color;
	}
	public void setColor(CardColor color) {
		this.color = color;
	}
	public CardSymbol getSymbol() {
		return symbol;
	}
	public void setSymbol(CardSymbol symbol) {
		this.symbol = symbol;
	}
}
