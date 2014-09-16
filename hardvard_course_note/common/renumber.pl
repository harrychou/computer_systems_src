#! /usr/bin/perl

die if @ARGV < 2
    || ($ARGV[0] eq "-i" && @ARGV != 2)
    || ($ARGV[0] eq "-d" && @ARGV != 2)
    || ($ARGV[0] eq "-r" && @ARGV != 3)
    || ($ARGV[0] ne "-i" && $ARGV[0] ne "-d" && $ARGV[0] ne "-r");

sub separate ($) {
    my($pat) = @_;
    die if !($pat =~ m,^(\S+?)(\d+)$,);
    die if index($pat, "/") >= 0;
    return ($1, int($2), length($2));
}

my($pfx, $num, $nlen) = separate($ARGV[1]);
my($plen, $tlen) = (length($pfx), length($pfx) + $nlen);
opendir(DIR, ".");
@files = sort { $a cmp $b } grep {
    substr($_, 0, $plen) eq $pfx
        && length($_) >= $tlen
        && substr($_, $plen) =~ m,\A\d+(?:|[^\d].*)\z,;
} readdir DIR;
closedir DIR;

sub namenum ($) {
    int(substr($_[0], $plen, $nlen));
}

sub newname ($$) {
    my($name, $delta) = @_;
    sprintf("%s%0${nlen}d%s", $pfx, namenum($name) + $delta,
            substr($name, $tlen));
}

sub renamename ($) {
    my($name) = @_;
    ".renumber.$name";
}

if ($ARGV[0] eq "-i") {
    for (my $pos = @files - 1; $pos >= 0; $pos -= 1) {
        last if namenum($files[$pos]) < $num;
        rename($files[$pos], newname($files[$pos], 1)) or die;
    }
} elsif ($ARGV[0] eq "-d") {
    for (my $pos = 0; $pos < @files; $pos += 1) {
        if (namenum($files[$pos]) == $num) {
            unlink($files[$pos]) or die;
        } elsif (namenum($files[$pos]) > $num) {
            rename($files[$pos], newname($files[$pos], -1)) or die;
        }
    }
} elsif ($ARGV[0] eq "-r") {
    my($pfx2, $num2, $nlen2) = separate($ARGV[2]);
    die if $pfx2 ne $pfx || $nlen2 != $nlen;
    for (my $pos = 0; $pos < @files; $pos += 1) {
        if (namenum($files[$pos]) == $num) {
            rename($files[$pos], renamename($files[$pos])) or die;
        }
    }
    if ($num < $num2) {
        for (my $pos = 0; $pos < @files; $pos += 1) {
            my($nn) = namenum($files[$pos]);
            if ($nn > $num && $nn <= $num2) {
                rename($files[$pos], newname($files[$pos], -1)) or die;
            }
        }
    } elsif ($num > $num2) {
        for (my $pos = @files - 1; $pos >= 0; $pos -= 1) {
            my($nn) = namenum($files[$pos]);
            if ($nn >= $num2 && $nn < $num) {
                rename($files[$pos], newname($files[$pos], 1)) or die;
            }
        }
    }
    for (my $pos = 0; $pos < @files; $pos += 1) {
        if (namenum($files[$pos]) == $num) {
            rename(renamename($files[$pos]), newname($files[$pos], $num2 - $num)) or die;
        }
    }
}
