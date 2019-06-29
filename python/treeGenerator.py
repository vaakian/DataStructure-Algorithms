import pymysql
from queue import Queue
from graphviz import Digraph

dot = Digraph(comment='chuanxiao tree')

# flush privileges;
db = pymysql.connect("192.168.110.110","root","b86551ee7ffc7eb5","ypzxw")
cursor = db.cursor()
pid = 1
userQueue = Queue()
def fetch_by_id(usr, pid, lv):
	cursor.execute('''SELECT *
					FROM m_userinfo
					WHERE pid={}'''.format(pid))

	users = cursor.fetchall()
	for user in users:
		print(user, 'lv:', lv)
		if user[-1] == usr:
			exit(0)
	for user in users:
		fetch_by_id(usr, user[0], lv+1)

def fetch_all_next(pid):
	cursor.execute('''SELECT *
					FROM m_userinfo
					WHERE pid={}'''.format(pid))
	result = list(cursor.fetchall())
	return result
lv2 = 1
def fetch_queue(pname, pid):
	global lv2
	users, flag_t = fetch_all_next(2)
	for user in users:
		try:

			userQueue.put(list(user))
		except:
			userQueue.put(user)
	lv = 1
	while True:
		user = userQueue.get()
		print(user, 'lv:', lv)
		if isinstance(user, int):
			lv = lv + 1
			continue
		if user[-1] == pname:
			exit(0)
		users, t_flag = fetch_one1(user[0])
		for user in users:
			try:
				temp_list = list(user)
				temp_list.append(lv2)
				userQueue.put(temp_list)
			except:
				userQueue.put((user))
		lv2 = lv2 + 1
pname = 'lkj8'
def get_name_by_id(id):
	cursor.execute('''SELECT user_name
					FROM m_userdata
					WHERE user_id={}'''.format(id))
	result = list(cursor.fetchone())
	return str(result[0])
def fetch_level(pid, level):
	last_lv = level
	next_users = fetch_all_next(pid)
	for next_user in next_users:
		userQueue.put([next_user, level + 1])
	while not userQueue.empty():
		cur_user = userQueue.get()# [(usr), lev]
		# 满足条件，找到该用户，结束运行
		# if cur_user[0][-1] == pname:
		# 	break
		# 当前层
		cur_level = cur_user[1]

		# 不同层换行
		if last_lv != cur_level:
			print('\n')
			last_lv = cur_level
		# 输出该用户信息
		print(cur_user)
		# 画图
		
		dot.node(get_name_by_id(cur_user[0][1])) # pid，pname
		# 把当前节点与父亲连起来
		if cur_user[0][0] != pid:
			dot.edge(get_name_by_id(cur_user[0][1]), get_name_by_id(cur_user[0][0]))
		print('edge add*********', cur_user[0][-1])

		# 最后将该用户的下级入队列
		next_users = fetch_all_next(cur_user[0][0])
		for next_user in next_users:
			userQueue.put([next_user, cur_level + 1])
# fetch_queue(pname='lkj8', pid=1)
# fetch_by_id(usr='lkj8', pid=1, lv=1)
fetch_level(pid=1, level=0)
dot.render('full.pdf', view=True)