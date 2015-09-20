
# analyse all the binary
aaa
e cfg.fortunes=false

# get the addr of the ptrace anti debug scheme
(get_error_debug, fs strings , k error_debug=`f~:0[0]` , axt `k error_debug`~[1])

# print the function called here
pdf @ `.(get_error_debug)`

?e [-] patch ptrace trick

# patch the exit call
(get_addr_call_exit, pdf @ `.(get_error_debug)`~imp.exit[0])
# overwrite the push and the call
?=`.(get_addr_call_exit)` - 2
s `??`
wx 90909090909090
pdf @ `.(get_error_debug)`
?e [-] ptrace trick bypassed, starting to debug

# start to debug
?e [-] start debugging

(goto_and_info addr, dcu $0, dbt, pdf)
.(goto_and_info main)
.(goto_and_info sym.bcheck)

?e [-] let create_check decypher the function check_f
.(goto_and_info sym.check2)
af check_ftw obj.check_f
.(goto_and_info check_ftw)

?e [-] Now read the flag.
