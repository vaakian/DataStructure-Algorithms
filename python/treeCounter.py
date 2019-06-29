import pymysql
from queue import Queue
from graphviz import Digraph

dot = Digraph(comment='chuanxiao tree')

# flush privileges;
db = pymysql.connect("192.168.110.110","root","b86551ee7ffc7eb5","ypzxw")
cursor = db.cursor()
userQueue = Queue()
def fetch_all_next(pid):
	cursor.execute('''SELECT *
					FROM m_userinfo
					WHERE pid={}'''.format(pid))
	result = list(cursor.fetchall())
	return result
lv2 = 1
pname = 'lkj8'
def get_name_by_id(id):
	cursor.execute('''SELECT user_name
					FROM m_userdata
					WHERE user_id={}'''.format(id))
	result = list(cursor.fetchone())
	return str(result[0])
def fetch_level(pid, level):
	sum = 0
	last_lv = level
	next_users = fetch_all_next(pid)
	for next_user in next_users:
		userQueue.put([next_user, level + 1])
		sum = sum + 1
	while not userQueue.empty():
		cur_user = userQueue.get()# [(usr), lev]
		# 满足条件，找到该用户，结束运行
		# if cur_user[0][-1] == pname:
		# 	break
		# 当前层
		cur_level = cur_user[1]

		# 不同层换行
		if last_lv != cur_level:
			# print('\n')
			last_lv = cur_level
		# 输出该用户信息
		# print(cur_user)
		# 最后将该用户的下级入队列
		next_users = fetch_all_next(cur_user[0][0])
		for next_user in next_users:
			userQueue.put([next_user, cur_level + 1])
			sum = sum + 1
	return sum
# 1. 下级会员总和大于30
# 2. 且下级会员账号多余三层 => 56-当前会员所在层>3，level>52 return 0
# count = 0
def fetch_by_id(pid, lv):
	global user
	users = fetch_all_next(pid)
	if not users:
		return 0
	count = 0
	for user in users:
		count = count + 1 + fetch_by_id(user[0], lv+1)
	for user in users:
		if count > 30 and lv <= 52:
			print(user, 'lv:', lv, count)
	return count
	# count 算上自己了的
	# count = count + 1
	# if count > 30 and lv <= 52:
	# 	print('good', count, lv, user)
count = fetch_by_id(1, 1)
print(count)
# for i in range(5, 50):
# 	count = fetch_level(pid=i, level=0)
# 	print(count)

# dot.render('full.pdf', view=True)