#include "interactive_mode.h"

#include <string>
#include "ip/mac_address.h"
#include "ip/address_factory.h"
#include "priority_queues/priority_queue_array.h"
#include "priority_queues/priority_queue_heap.h"
#include "priority_queues/priority_queue_list.h"
#include "priority_queues/priority_queue_tree.h"

void interactive_mode::run(std::ostream &out, std::istream &in)
{
    out << "Welcome to the interactive mode!\n";
    queue = std::make_unique<priority_queue_tree<ipv6_address>>();
    print_help(out);
    std::string input;
    while(true)
    {
        out << "> ";
        in >> input;
        if(input == "exit")
            break;
        else if(input == "help")
            print_help(out);
        else if(input == "create-queue")
            create_queue_command(out, in);
        else if(input == "peek")
        {
            try
            {
                ipv6_address element = queue->peek();
                out << "Highest-priority element: " << element << std::endl;
            }
            catch(const std::out_of_range& e)
            {
                out << "\nError: " << e.what() << std::endl;
            }
        }
        else if(input == "pop")
        {
            try
            {
                ipv6_address element = queue->pop();
                out << "Popped element " << element << std::endl;
            }
            catch(const std::out_of_range& e)
            {
                out << "\nError: " << e.what() << std::endl;
            }
        }
        else if(input == "print")
            out << *queue << std::endl;
        else if(input == "push")
            push_command(out, in);
        else if(input == "ipv6-from-mac")
            ipv6_from_mac_command(out, in);
        else if(input == "check-subnet")
            check_subnet_command(out, in);
    }
}

void interactive_mode::print_help(std::ostream &out)
{
    out << "Available commands:\n";
    out << "Queue commands: create-queue, push, pop, peek, print\n";
    out << "IP commands: ipv6-from-mac, check-subnet\n";
    out << "Other commands: help, exit\n";
}

void interactive_mode::create_queue_command(std::ostream &out, std::istream &in)
{
    out << "Deleting old queue...\n";
    queue.reset();

    out << "Select new queue type:\n";
    char c;
    bool success = false;
    while(!success)
    {
        out << "(a = array, h = heap, t = tree, l = list) ";

        in >> c;

        if(c == 'a')
        {
            success = true;
            queue = std::make_unique<priority_queue_array<ipv6_address>>();
        }
        else if(c == 'h')
        {
            success = true;
            queue = std::make_unique<priority_queue_heap<ipv6_address>>();
        }
        else if(c == 't')
        {
            success = true;
            queue = std::make_unique<priority_queue_tree<ipv6_address>>();
        }
        else if(c == 'l')
        {
            success = true;
            queue = std::make_unique<priority_queue_list<ipv6_address>>();
        }
    }
}

void interactive_mode::push_command(std::ostream &out, std::istream &in)
{
    out << "Enter address: ";
    std::string input;
    in >> input;
    ipv6_address address = address_factory::parse_address_as_ipv6(input);
    queue->add(address);
}

void interactive_mode::ipv6_from_mac_command(std::ostream &out, std::istream &in)
{
    out << "Enter MAC address: ";
    std::string input;
    in >> input;
    mac_address address = address_factory::parse_mac_address(input);
    out << "Autoconfigured local IPv6 address: " << address_factory::local_ipv6_from_mac_auto(address) << std::endl;
}

void interactive_mode::check_subnet_command(std::ostream &out, std::istream &in)
{
    out << "Enter IP address: ";
    std::string input;
    in >> input;
    ipv6_address address = address_factory::parse_address_as_ipv6(input);
    out << "Enter subnet address with subnet mask: ";
    in >> input;
    ipv6_address subnet_address = address_factory::parse_subnet_address_as_ipv6(input);
    if(address.belongs_to_subnet(subnet_address))
        out << address << " belongs to " << subnet_address << '.' << std::endl;
    else
        out << address << " does not belong to " << subnet_address << '.' << std::endl;
}