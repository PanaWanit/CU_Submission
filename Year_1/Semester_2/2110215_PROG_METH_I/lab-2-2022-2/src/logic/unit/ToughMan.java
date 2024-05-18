package logic.unit;

public class ToughMan extends BaseCompetitor {
	private int maxHp;
	public ToughMan(String name) {
		super(name, 8, 4);
		setMaxHp(8);
	}
	public ToughMan(String name, int hp, int power) {
		super(name, hp, power);
		setMaxHp(hp);
	}
	public void heal(int healUp) {
		healUp = Math.max(healUp, 0);
		setHp(Math.min(healUp + getHp(), maxHp));
	}

	@Override
	public void attack(BaseCompetitor enemy) {
		if (enemy.getType().equals("Sorcerer")) {
			int enemyHp = enemy.getHp() - getPower()/2;
			enemy.setHp(enemyHp);
		}
		else if(enemy.getType().equals("ToughMan") || enemy.getType().equals("BaseCompetitor")) {
			super.attack(enemy);
		}
		else {
			int enemyHp = enemy.getHp() - 3*getPower()/2;
			enemy.setHp(enemyHp);
		}
	}
	// getter and setter
	public int getMaxHp() {
		return maxHp;
	}
	public void setMaxHp(int maxHp) {
		this.maxHp = Math.max(maxHp, 0);
		setHp(Math.min(this.maxHp, getHp()));
	}
}
