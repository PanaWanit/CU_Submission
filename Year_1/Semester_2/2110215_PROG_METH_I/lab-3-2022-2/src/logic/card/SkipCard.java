package logic.card;

import logic.game.CardColor;
import logic.game.CardSymbol;
import logic.game.GameLogic;

//You CAN modify the first line
public class SkipCard extends EffectCard {
	public SkipCard(CardColor color) {
		super(color, CardSymbol.SKIP);
	}
	@Override
	public String performEffect() {
		GameLogic.getInstance().goToNextPlayer();
		while(GameLogic.getInstance().getCurrentPlayerHand().isEmpty()) {
			GameLogic.getInstance().goToNextPlayer();
		}
		String ans = "Skipped player " + GameLogic.getInstance().getCurrentPlayer();
		while(GameLogic.getInstance().getCurrentPlayerHand().isEmpty()) {
			GameLogic.getInstance().goToNextPlayer();
		}
		return ans;
	}

	@Override
	public boolean canPlay() {
		BaseCard top = GameLogic.getInstance().getTopCard();
		return (top.getColor().equals(getColor()) || top.getSymbol().equals(getSymbol()));
	}

	@Override
	public String toString() {
		return getColor() + " " + getSymbol();	
	}
    // TODO Implement here
	

}
