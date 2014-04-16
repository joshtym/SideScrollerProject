all:
	$(MAKE) -C src

tests:
	$(MAKE) -C src tests
	
clean:
	$(MAKE) -C src clean
