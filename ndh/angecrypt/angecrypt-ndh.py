from Crypto.Cipher import AES


algo = AES.new('Polyglot-File007', AES.MODE_CBC, "O\xc6\xfaZ?\xa8_^0\x17\xab*\xf6\xa6\x9b\xc7")

with open('profiling-ndh2k15-forrelease.pdf', "rb") as f:
        d = f.read()

d = algo.encrypt(d)

with open("soluce", "wb") as f:
        f.write(d)
