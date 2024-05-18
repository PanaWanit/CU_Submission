package logic.card;

import logic.game.CardColor;
import logic.game.CardSymbol;
import logic.game.GameLogic;

import java.util.ArrayList;

//You CAN modify the first line
public class DrawTwoCard extends EffectCard {

	public DrawTwoCard(CardColor color) {
		super(color, CardSymbol.DRAW_TWO);
	}

	@Override
	public String performEffect() {
		GameLogic gameInstance = GameLogic.getInstance();
		gameInstance.goToNextPlayer();
		while(gameInstance.getCurrentPlayerHand().isEmpty()) {
			gameInstance.goToNextPlayer();
		}
		gameInstance.incrementDrawAmount(2);
		ArrayList<BaseCard> CurrentPlayerHand = gameInstance.getCurrentPlayerHand();
		String result = "";
		boolean use_card = false;
		for(int i=0; i<CurrentPlayerHand.size(); i++) {
			if(CurrentPlayerHand.get(i).getSymbol() != CardSymbol.DRAW_TWO && CurrentPlayerHand.get(i).getSymbol() != CardSymbol.DRAW_FOUR) continue;
			result += "Player " + gameInstance.getCurrentPlayer() + " played " + CurrentPlayerHand.get(i) + ". " + (CurrentPlayerHand.size()-1) + " cards remaining.\n";
			result += CurrentPlayerHand.get(i).play();
			use_card = true;
			break;
		}
		if(use_card == false) {
			int drawAmt = gameInstance.draw(gameInstance.getDrawAmount()).size();
			result += "Player " + gameInstance.getCurrentPlayer() + " drew " + drawAmt + " cards. " + CurrentPlayerHand.size() + " cards remaining.";
			gameInstance.setDrawAmount(0);
		}
		return result;
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

}
