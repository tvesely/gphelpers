#!/usr/bin/perl

my $input_path=$ARGV[0];
my $output_path=$ARGV[1];
my $query_file;
my $query_started;
print $output_path;
open(my $fh, '<', $input_path)
 or die("Could not open input file");

while (<$fh>) {
    if (/start query (\d+)/) {
        my $query_number=$1;
        $query_started = 1;
        open($query_file, '>', "$output_path/query$query_number.sql")
          or die("Could not open file");
        print $query_file ":EXPLAIN ANALYZE\n";
        print "start of query $query_number\n";

    } elsif (/end query/) {
        $query_started = 0;
        print "end of query $query_number\n";
        close $query_file;
    }  else {
        print $query_file $_;
    }
}

close $fh;
