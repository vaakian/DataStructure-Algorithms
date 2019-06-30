import hashlib
f = open('password.txt', 'r')
salt = 'a9a8e7bc78'
salted_hash = 'ea536bb7d8e51acc92f280fdea7798f21819dd13'

pwd = f.readline()
while pwd:
	pwd = pwd.strip('\n') + salt # 加盐
	pwd = pwd.encode('utf-8')
	current_hash = hashlib.sha1(pwd).hexdigest()
	if current_hash == salted_hash:
		print('password:', pwd.decode('utf-8')[:-10])
		break
	pwd = f.readline()
f.close()
