package logic.unit;

public class Tiger extends BaseCompetitor {
	public Tiger(String name) {
		super(name, 7, 5);
	}
	public Tiger(String name, int hp, int power) {
		super(name, hp, power);
	}
	public void train(int addPower) {
		setPower(getPower() + Math.max(0, addPower));
	}
	
	@Override
	public void attack(BaseCompetitor enemy) {
		if(enemy.getType().equals("ToughMan")) {
			enemy.setHp(enemy.getHp() - getPower()/2);
		}
		else if(enemy.getType().equals("Tiger") || enemy.getType().equals("BaseCompetitor")) {
			super.attack(enemy);
		}
		else {
			int enemyHp = enemy.getHp() - 3*getPower()/2;
			enemy.setHp(enemyHp);
		}
	}
}
