COMPILERDIR=Compiler
MUSICDIR=Files
NXTDIR=NXT

MUSIC=$(patsubst %.mus,%.nms,$(subst $(MUSICDIR),$(NXTDIR),$(wildcard $(MUSICDIR)/*.mus)))

$(NXTDIR)/%.nms: $(MUSICDIR)/%.mus MusicCompiler
	./MusicCompiler $< $@

all: $(MUSIC)

clean:
	rm MusicCompiler

MusicCompiler:
	make -C $(COMPILERDIR)
	cp $(COMPILERDIR)/MusicCompiler ./
	make -C $(COMPILERDIR) clean

.PHONY: all clean
